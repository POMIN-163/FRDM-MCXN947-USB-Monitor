#ifndef LV_CONF_H
#define LV_CONF_H

#include <rtconfig.h>

#define LV_USE_SYSMON           1
#define LV_USE_PERF_MONITOR     0
#define LV_COLOR_DEPTH          16

#define LV_HOR_RES_MAX          240
#define LV_VER_RES_MAX          320
#define LV_COLOR_16_SWAP        0

#define BSP_USING_LVGL_BENCHMARK_DEMO
#define BSP_USING_LVGL_WIDGETS_DEMO

#ifdef BSP_USING_LVGL_DAVE2D
    #define LV_USE_DRAW_DAVE2D      1
#endif

/*turn-on helium acceleration when Arm-2D and the Helium-powered device are detected */
#ifdef BSP_USING_LVGL_ARM2D
    #if defined(__ARM_FEATURE_MVE) && __ARM_FEATURE_MVE
        #define LV_USE_DRAW_SW_ASM  LV_DRAW_SW_ASM_HELIUM
        #define LV_USE_DRAW_ARM2D       1
        #define LV_USE_DRAW_ARM2D_SYNC  1
    #endif
#endif

#ifdef BSP_USING_LVGL_WIDGETS_DEMO
    #define LV_USE_DEMO_WIDGETS 1
    #define LV_DEMO_WIDGETS_SLIDESHOW   0
#endif  /* BSP_USING_LVGL_WIDGETS_DEMO */

/*Benchmark your system*/
#ifdef BSP_USING_LVGL_BENCHMARK_DEMO
    #define LV_USE_DEMO_BENCHMARK 1
    /*Use RGB565A8 images with 16 bit color depth instead of ARGB8565*/
    #define LV_DEMO_BENCHMARK_RGB565A8  1
    #define LV_FONT_MONTSERRAT_14       1
    #define LV_FONT_MONTSERRAT_24       1
#endif  /* BSP_USING_LVGL_BENCHMARK_DEMO */

/*Stress test for LVGL*/
#ifdef BSP_USING_LVGL_STRESS_DEMO
    #define LV_USE_DEMO_STRESS 1
#endif  /* BSP_USING_LVGL_STRESS_DEMO */

/*Render test for LVGL*/
#ifdef BSP_USING_LVGL_RENDER_DEMO
    #define LV_USE_DEMO_RENDER 1
#endif  /* BSP_USING_LVGL_RENDER_DEMO */

/*Music player demo*/
#ifdef BSP_USING_LVGL_MUSIC_DEMO
    #define LV_USE_DEMO_MUSIC 1
    #define LV_DEMO_MUSIC_SQUARE    1
    #define LV_DEMO_MUSIC_LANDSCAPE 0
    #define LV_DEMO_MUSIC_ROUND     0
    #define LV_DEMO_MUSIC_LARGE     0
    #define LV_DEMO_MUSIC_AUTO_PLAY 0
    #define LV_FONT_MONTSERRAT_12   1
    #define LV_FONT_MONTSERRAT_16   1
#endif  /* BSP_USING_LVGL_MUSIC_DEMO */

// /*Garbage Collector settings
//  *Used if lvgl is bound to higher level language and the memory is managed by that language*/
// #define LV_ENABLE_GC 0 /* Enable GC for Micropython */
// #if LV_ENABLE_GC != 0
//     #define LV_GC_INCLUDE "py/mpstate.h"
//     #define LV_MEM_CUSTOM_GET_SIZE  gc_nbytes      /*Wrapper to lv_mem_get_size*/
//     #define LV_GC_ROOT(x) MP_STATE_PORT(x)
// #endif /*LV_ENABLE_GC*/
// #include "py/qstr.h"


#endif
