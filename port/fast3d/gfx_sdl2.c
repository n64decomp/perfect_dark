#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#include "gfx_window_manager_api.h"
#include "gfx_screen_config.h"

#define GFX_API_NAME "SDL2 - OpenGL"

static SDL_Window *wnd;
static int vsync_enabled = 0;
static unsigned int window_width = DESIRED_SCREEN_WIDTH;
static unsigned int window_height = DESIRED_SCREEN_HEIGHT;
static bool fullscreen_state;
static void (*on_fullscreen_changed_callback)(bool is_now_fullscreen);

static void set_fullscreen(bool on, bool call_callback) {
    if (fullscreen_state == on) {
        return;
    }
    fullscreen_state = on;

    if (on) {
        SDL_DisplayMode mode;
        SDL_GetDesktopDisplayMode(0, &mode);
        window_width = mode.w;
        window_height = mode.h;
    } else {
        window_width = DESIRED_SCREEN_WIDTH;
        window_height = DESIRED_SCREEN_HEIGHT;
    }
    SDL_SetWindowSize(wnd, window_width, window_height);
    SDL_SetWindowFullscreen(wnd, on ? SDL_WINDOW_FULLSCREEN : 0);

    if (on_fullscreen_changed_callback != NULL && call_callback) {
        on_fullscreen_changed_callback(on);
    }
}

static void test_vsync(void) {
    // Even if SDL_GL_SetSwapInterval succeeds, it doesn't mean that VSync actually works.
    // A 60 Hz monitor should have a swap interval of 16.67 milliseconds.
    // Try to detect the length of a vsync by swapping buffers some times.
    // Since the graphics card may enqueue a fixed number of frames,
    // first send in four dummy frames to hopefully fill the queue.
    // This method will fail if the refresh rate is changed, which, in
    // combination with that we can't control the queue size (i.e. lag)
    // is a reason this generic SDL2 backend should only be used as last resort.
    Uint32 start;
    Uint32 end;

    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    start = SDL_GetTicks();
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    SDL_GL_SwapWindow(wnd);
    end = SDL_GetTicks();

    float average = 4.0 * 1000.0 / (end - start);

    vsync_enabled = 1;
    if (average > 27 && average < 33) {
        SDL_GL_SetSwapInterval(1);
    } else if (average > 57 && average < 63) {
        SDL_GL_SetSwapInterval(2);
    } else if (average > 86 && average < 94) {
        SDL_GL_SetSwapInterval(3);
    } else if (average > 115 && average < 125) {
        SDL_GL_SetSwapInterval(4);
    } else {
        vsync_enabled = 0;
    }
}

static void gfx_sdl_init(const char *game_name, bool start_in_fullscreen) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    char title[512];
    int len = sprintf(title, "%s (%s)", game_name, GFX_API_NAME);

    wnd = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            window_width, window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (start_in_fullscreen) {
        set_fullscreen(true, false);
    }

    SDL_GL_CreateContext(wnd);

    SDL_GL_SetSwapInterval(1);
    test_vsync();
    if (!vsync_enabled)
        puts("Warning: VSync is not enabled or not working. Falling back to timer for synchronization");
}

static void gfx_sdl_set_fullscreen_changed_callback(void (*on_fullscreen_changed)(bool is_now_fullscreen)) {
    on_fullscreen_changed_callback = on_fullscreen_changed;
}

static void gfx_sdl_set_fullscreen(bool enable) {
    set_fullscreen(enable, true);
}

static void gfx_sdl_main_loop(void (*run_one_game_iter)(void)) {
    while (1) {
        run_one_game_iter();
    }
}

static void gfx_sdl_get_dimensions(uint32_t *width, uint32_t *height) {
    *width = window_width;
    *height = window_height;
}

static void gfx_sdl_handle_events(void) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    window_width = event.window.data1;
                    window_height = event.window.data2;
                }
                break;
            case SDL_QUIT:
                exit(0);
        }
    }
}

static bool gfx_sdl_start_frame(void) {
    return true;
}

static void sync_framerate_with_timer(void) {
    // Number of milliseconds a frame should take (60 fps)
    const Uint32 FRAME_TIME = 1000 / 60;
    static Uint32 last_time;
    Uint32 elapsed = SDL_GetTicks() - last_time;

    if (elapsed < FRAME_TIME)
        SDL_Delay(FRAME_TIME - elapsed);
    last_time += FRAME_TIME;
}

static void gfx_sdl_swap_buffers_begin(void) {
    if (!vsync_enabled) {
        sync_framerate_with_timer();
    }

    SDL_GL_SwapWindow(wnd);
}

static void gfx_sdl_swap_buffers_end(void) {
}

static double gfx_sdl_get_time(void) {
    return 0.0;
}

static void *gfx_sdl_get_window_handle(void) {
    return wnd;
}

struct GfxWindowManagerAPI gfx_sdl = {
    gfx_sdl_init,
    gfx_sdl_set_fullscreen_changed_callback,
    gfx_sdl_set_fullscreen,
    gfx_sdl_main_loop,
    gfx_sdl_get_dimensions,
    gfx_sdl_handle_events,
    gfx_sdl_start_frame,
    gfx_sdl_swap_buffers_begin,
    gfx_sdl_swap_buffers_end,
    gfx_sdl_get_time,
    gfx_sdl_get_window_handle,
};
