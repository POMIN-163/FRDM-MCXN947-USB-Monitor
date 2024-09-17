/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_time;
	lv_obj_t *screen_date;
	lv_obj_t *screen_left;
	lv_obj_t *screen_label_cpu_temp;
	lv_obj_t *screen_label_cpu_load;
	lv_obj_t *screen_label_cpu_fan;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_6;
	lv_obj_t *screen_label_11;
	lv_obj_t *screen_label_13;
	lv_obj_t *screen_label_14;
	lv_obj_t *screen_label_15;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_animimg_spaceman;
	lv_obj_t *screen_right;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_img_3;
	lv_obj_t *screen_label_temp;
	lv_obj_t *screen_label_load;
	lv_obj_t *screen_arc_gpu_temp;
	lv_obj_t *screen_arc_gpu_load;
	lv_obj_t *screen_bar_gpu_fan;
	lv_obj_t *screen_bar_gpu_vol;
	lv_obj_t *screen_bar_gpu_watt;
	lv_obj_t *screen_label_gpu_load;
	lv_obj_t *screen_label_gpu_temp;
	lv_obj_t *screen_label_gpu_vol;
	lv_obj_t *screen_label_gpu_watt;
	lv_obj_t *screen_label_gpu_fan;
	lv_obj_t *screen_img_load;
	lv_obj_t *screen_label_3;
	lv_obj_t *screen_label_7;
	lv_obj_t *screen_label_17;
	lv_obj_t *screen_label_10;
	lv_obj_t *screen_label_18;
	lv_obj_t *screen_label_19;
	lv_obj_t *screen_label_23;
	lv_obj_t *screen_label_V;
	lv_obj_t *screen_label_W;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_cpu_alpha_16x16);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_animimg_spacemanloading00);
LV_IMG_DECLARE(screen_animimg_spacemanloading01);
LV_IMG_DECLARE(screen_animimg_spacemanloading02);
LV_IMG_DECLARE(screen_animimg_spacemanloading03);
LV_IMG_DECLARE(screen_animimg_spacemanloading04);
LV_IMG_DECLARE(screen_animimg_spacemanloading05);
LV_IMG_DECLARE(screen_animimg_spacemanloading06);
LV_IMG_DECLARE(screen_animimg_spacemanloading07);
LV_IMG_DECLARE(screen_animimg_spacemanloading08);
LV_IMG_DECLARE(screen_animimg_spacemanloading09);
LV_IMG_DECLARE(screen_animimg_spacemanloading10);
LV_IMG_DECLARE(screen_animimg_spacemanloading11);
LV_IMG_DECLARE(screen_animimg_spacemanloading12);
LV_IMG_DECLARE(screen_animimg_spacemanloading13);
LV_IMG_DECLARE(screen_animimg_spacemanloading14);
LV_IMG_DECLARE(screen_animimg_spacemanloading15);
LV_IMG_DECLARE(screen_animimg_spacemanloading16);
LV_IMG_DECLARE(_gpu_alpha_16x16);
LV_IMG_DECLARE(_temp_alpha_12x12);
LV_IMG_DECLARE(_load_alpha_12x12);

LV_FONT_DECLARE(lv_font_04B_08_24)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_04B_08_8)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_14)
LV_FONT_DECLARE(lv_font_montserratMedium_10)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_10)
LV_FONT_DECLARE(lv_font_Acme_Regular_18)
LV_FONT_DECLARE(lv_font_Acme_Regular_16)


#ifdef __cplusplus
}
#endif
#endif
