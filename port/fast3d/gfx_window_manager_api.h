#ifndef GFX_WINDOW_MANAGER_API_H
#define GFX_WINDOW_MANAGER_API_H

#include <stdint.h>
#include <stdbool.h>

struct GfxWindowManagerAPI {
    void (*init)(const char* game_name, const char* gfx_api_name, bool start_in_fullscreen, uint32_t width,
                 uint32_t height, int32_t posX, int32_t posY);
    void (*close)(void);
    void (*set_fullscreen_changed_callback)(void (*on_fullscreen_changed)(bool is_now_fullscreen));
    void (*set_fullscreen)(bool enable);
    void (*get_active_window_refresh_rate)(uint32_t* refresh_rate);
    void (*set_cursor_visibility)(bool visible);
    void (*get_dimensions)(uint32_t* width, uint32_t* height, int32_t* posX, int32_t* posY);
    void (*handle_events)(void);
    bool (*start_frame)(void);
    void (*swap_buffers_begin)(void);
    void (*swap_buffers_end)(void);
    double (*get_time)(void); // For debug
    void (*set_target_fps)(int fps);
    bool (*can_disable_vsync)(void);
    void *(*get_window_handle)(void);
    void (*set_window_title)(const char *);
    void (*set_swap_interval)(int);
};

#endif
