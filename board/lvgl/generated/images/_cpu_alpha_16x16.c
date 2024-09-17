#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__CPU_ALPHA_16X16
#define LV_ATTRIBUTE_IMG__CPU_ALPHA_16X16
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__CPU_ALPHA_16X16 uint8_t _cpu_alpha_16x16_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0xb6, 0x92, 0x60, 0x00, 0x00, 0x00, 0x00, 0x92, 0x60, 0x92, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0xff, 0x92, 0x77, 0x00, 0x00, 0x00, 0x00, 0x92, 0x77, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x92, 0x30, 0x6e, 0xfa, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xfa, 0x92, 0x32, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6e, 0xfa, 0x92, 0x8e, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x92, 0x8e, 0x6e, 0xfa, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x92, 0xb6, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x6e, 0x2e, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0x2e, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x6e, 0xff, 0x92, 0xbb, 
  0x92, 0x60, 0x92, 0x77, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x6e, 0xff, 0x92, 0xb7, 0x92, 0x77, 0x92, 0x77, 0x92, 0xb7, 0x6e, 0xff, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x92, 0x77, 0x92, 0x60, 
  0x00, 0x00, 0x00, 0x00, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x6e, 0xff, 0x92, 0x77, 0x00, 0x00, 0x00, 0x00, 0x92, 0x77, 0x6e, 0xff, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x92, 0x11, 0x92, 0x3e, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x6e, 0xff, 0x92, 0x77, 0x00, 0x00, 0x00, 0x00, 0x92, 0x77, 0x6e, 0xff, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x92, 0x3e, 0x92, 0x11, 
  0x6e, 0xda, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x6e, 0xff, 0x92, 0xb7, 0x92, 0x77, 0x92, 0x77, 0x92, 0xb7, 0x6e, 0xff, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xda, 
  0x72, 0x0e, 0x6e, 0x18, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x6e, 0x2e, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0x2e, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x6e, 0x18, 0x72, 0x0e, 
  0x00, 0x00, 0x00, 0x00, 0x6e, 0xff, 0x6e, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x08, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6e, 0xfa, 0x92, 0x8e, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x6e, 0x08, 0x92, 0x8e, 0x6e, 0xfa, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x92, 0x2e, 0x6e, 0xfa, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xff, 0x6e, 0xfa, 0x92, 0x30, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0xff, 0x92, 0x77, 0x00, 0x00, 0x00, 0x00, 0x92, 0x77, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0xb6, 0x92, 0x60, 0x00, 0x00, 0x00, 0x00, 0x92, 0x60, 0x92, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcf, 0x73, 0xb6, 0xaf, 0x73, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaf, 0x73, 0x60, 0xaf, 0x73, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x11, 0x84, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x84, 0x77, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7b, 0x30, 0x6e, 0x6b, 0xfa, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xfa, 0xf1, 0x7b, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xfa, 0x11, 0x84, 0x8e, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x11, 0x84, 0x8e, 0x6e, 0x6b, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xcf, 0x73, 0xb6, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x8f, 0x6b, 0x2e, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x8f, 0x6b, 0x2e, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0xaf, 0x73, 0xbb, 
  0xaf, 0x73, 0x60, 0x11, 0x84, 0x77, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0xd0, 0x7b, 0xb7, 0x11, 0x84, 0x77, 0x11, 0x84, 0x77, 0xd0, 0x7b, 0xb7, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x11, 0x84, 0x77, 0xaf, 0x73, 0x60, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x11, 0x84, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x84, 0x77, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x8c, 0x11, 0x73, 0x94, 0x3e, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x11, 0x84, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x84, 0x77, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x73, 0x94, 0x3e, 0x53, 0x8c, 0x11, 
  0x8f, 0x73, 0xda, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0xd0, 0x7b, 0xb7, 0x11, 0x84, 0x77, 0x11, 0x84, 0x77, 0xd0, 0x7b, 0xb7, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x8f, 0x73, 0xda, 
  0x10, 0x74, 0x0e, 0x6f, 0x6b, 0x18, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x8f, 0x6b, 0x2e, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x8f, 0x6b, 0x2e, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x6f, 0x6b, 0x18, 0x10, 0x74, 0x0e, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x10, 0x63, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x63, 0x08, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xfa, 0x11, 0x84, 0x8e, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x10, 0x63, 0x08, 0x11, 0x84, 0x8e, 0x6e, 0x6b, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7b, 0x2e, 0x6e, 0x6b, 0xfa, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xff, 0x6e, 0x6b, 0xfa, 0xf0, 0x7b, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x6b, 0xff, 0x11, 0x84, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x84, 0x77, 0x6e, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7b, 0xb6, 0xaf, 0x73, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaf, 0x73, 0x60, 0xcf, 0x73, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0xcf, 0xb6, 0x73, 0xaf, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0xaf, 0x60, 0x73, 0xaf, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x84, 0x11, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x11, 0x77, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0xf0, 0x30, 0x6b, 0x6e, 0xfa, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xfa, 0x7b, 0xf1, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xfa, 0x84, 0x11, 0x8e, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x84, 0x11, 0x8e, 0x6b, 0x6e, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x73, 0xcf, 0xb6, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x8f, 0x2e, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x8f, 0x2e, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x73, 0xaf, 0xbb, 
  0x73, 0xaf, 0x60, 0x84, 0x11, 0x77, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x7b, 0xd0, 0xb7, 0x84, 0x11, 0x77, 0x84, 0x11, 0x77, 0x7b, 0xd0, 0xb7, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x84, 0x11, 0x77, 0x73, 0xaf, 0x60, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x84, 0x11, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x11, 0x77, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x8c, 0x53, 0x11, 0x94, 0x73, 0x3e, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x84, 0x11, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x11, 0x77, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x94, 0x73, 0x3e, 0x8c, 0x53, 0x11, 
  0x73, 0x8f, 0xda, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x7b, 0xd0, 0xb7, 0x84, 0x11, 0x77, 0x84, 0x11, 0x77, 0x7b, 0xd0, 0xb7, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x73, 0x8f, 0xda, 
  0x74, 0x10, 0x0e, 0x6b, 0x6f, 0x18, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x8f, 0x2e, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x8f, 0x2e, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x6b, 0x6f, 0x18, 0x74, 0x10, 0x0e, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x63, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x10, 0x08, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xfa, 0x84, 0x11, 0x8e, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x63, 0x10, 0x08, 0x84, 0x11, 0x8e, 0x6b, 0x6e, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0xf0, 0x2e, 0x6b, 0x6e, 0xfa, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xff, 0x6b, 0x6e, 0xfa, 0x7b, 0xf0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x6e, 0xff, 0x84, 0x11, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x11, 0x77, 0x6b, 0x6e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0xf0, 0xb6, 0x73, 0xaf, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0xaf, 0x60, 0x73, 0xcf, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Alpha 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0x76, 0x73, 0xb6, 0x7a, 0x75, 0x72, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7a, 0x75, 0x72, 0x60, 0x7b, 0x74, 0x71, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x87, 0x81, 0x7c, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x81, 0x7c, 0x77, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7a, 0x7a, 0x30, 0x73, 0x6d, 0x6b, 0xfa, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xfa, 0x85, 0x7a, 0x7a, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xfa, 0x87, 0x80, 0x7c, 0x8e, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x87, 0x80, 0x7c, 0x8e, 0x73, 0x6d, 0x6b, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x7b, 0x76, 0x73, 0xb6, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x74, 0x6f, 0x69, 0x2e, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x74, 0x6f, 0x69, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x7b, 0x74, 0x71, 0xbb, 
  0x7a, 0x75, 0x72, 0x60, 0x87, 0x81, 0x7c, 0x77, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x7f, 0x78, 0x76, 0xb7, 0x87, 0x81, 0x7c, 0x77, 0x87, 0x81, 0x7c, 0x77, 0x7f, 0x78, 0x76, 0xb7, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x87, 0x81, 0x7c, 0x77, 0x7a, 0x75, 0x72, 0x60, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x87, 0x81, 0x7c, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x81, 0x7c, 0x77, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x96, 0x87, 0x87, 0x11, 0x94, 0x8c, 0x8c, 0x3e, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x87, 0x81, 0x7c, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x81, 0x7c, 0x77, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x94, 0x8c, 0x8c, 0x3e, 0x96, 0x87, 0x87, 0x11, 
  0x76, 0x6f, 0x6e, 0xda, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x7f, 0x78, 0x76, 0xb7, 0x87, 0x81, 0x7c, 0x77, 0x87, 0x81, 0x7c, 0x77, 0x7f, 0x78, 0x76, 0xb7, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x76, 0x6f, 0x6e, 0xda, 
  0x80, 0x80, 0x6d, 0x0e, 0x75, 0x6a, 0x6a, 0x18, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x74, 0x6f, 0x69, 0x2e, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x74, 0x6f, 0x69, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x75, 0x6a, 0x6a, 0x18, 0x80, 0x80, 0x6d, 0x0e, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x80, 0x60, 0x60, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x60, 0x08, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xfa, 0x87, 0x80, 0x7c, 0x8e, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x80, 0x60, 0x60, 0x08, 0x87, 0x80, 0x7c, 0x8e, 0x73, 0x6d, 0x6b, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7a, 0x74, 0x2e, 0x73, 0x6d, 0x6b, 0xfa, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xff, 0x73, 0x6d, 0x6b, 0xfa, 0x80, 0x7a, 0x7a, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6d, 0x6b, 0xff, 0x87, 0x81, 0x7c, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x81, 0x7c, 0x77, 0x73, 0x6d, 0x6b, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x7a, 0x77, 0xb6, 0x7a, 0x75, 0x72, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7a, 0x75, 0x72, 0x60, 0x7b, 0x76, 0x73, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t _cpu_alpha_16x16 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 16,
  .header.h = 16,
  .data_size = 256 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _cpu_alpha_16x16_map,
};
