#ifndef GFX_API_H
#define GFX_API_H

#ifndef __cplusplus
#include <stdint.h>
#include <stdbool.h>
#endif

#include "gfx_rendering_api.h"
#include "gfx_window_manager_api.h"

struct XYWidthHeight {
    int16_t x, y;
    uint32_t width, height;
};

struct GfxDimensions {
    float internal_mul;
    uint32_t width, height;
    float aspect_ratio;
};

extern struct GfxDimensions gfx_current_window_dimensions; // The dimensions of the window
extern struct GfxDimensions
    gfx_current_dimensions; // The dimensions of the draw area the game draws to, before scaling (if applicable)
extern struct XYWidthHeight
    gfx_current_game_window_viewport; // The area of the window the game is drawn to, (0, 0) is top-left corner
extern uint32_t gfx_msaa_level;
extern struct XYWidthHeight gfx_current_native_viewport; // The internal/native video mode of the game

void gfx_init(struct GfxWindowManagerAPI* wapi, struct GfxRenderingAPI* rapi, const char* game_name,
              bool start_in_fullscreen, uint32_t width, uint32_t height,
              uint32_t posX, uint32_t posY);
void gfx_destroy(void);
struct GfxRenderingAPI* gfx_get_current_rendering_api(void);
void gfx_start_frame(void);
void gfx_run(Gfx* commands);
void gfx_end_frame(void);
void gfx_set_target_fps(int);
void gfx_set_maximum_frame_latency(int latency);
void gfx_texture_cache_clear(void);
int gfx_create_framebuffer(uint32_t width, uint32_t height);
void gfx_set_framebuffer(int fb, float noise_scale) ;
void gfx_reset_framebuffer(void);
void gfx_copy_framebuffer(int fb_dst, int fb_src, int left, int top);
void gfx_get_pixel_depth_prepare(float x, float y);
uint16_t gfx_get_pixel_depth(float x, float y);

#endif
