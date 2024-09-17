/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 320, 240);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_time
	ui->screen_time = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_time, "12:00");
	lv_label_set_long_mode(ui->screen_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_time, 0, 10);
	lv_obj_set_size(ui->screen_time, 120, 24);

	//Write style for screen_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_time, &lv_font_04B_08_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_date
	ui->screen_date = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_date, "2024.09.08");
	lv_label_set_long_mode(ui->screen_date, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_date, 0, 40);
	lv_obj_set_size(ui->screen_date, 120, 8);

	//Write style for screen_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_date, &lv_font_04B_08_8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_date, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_left
	ui->screen_left = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_left, 5, 55);
	lv_obj_set_size(ui->screen_left, 115, 180);
	lv_obj_set_scrollbar_mode(ui->screen_left, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_left, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_left, lv_color_hex(0x848284), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_left, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_left, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_cpu_temp
	ui->screen_label_cpu_temp = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_cpu_temp, "00");
	lv_label_set_long_mode(ui->screen_label_cpu_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_cpu_temp, 45, 30);
	lv_obj_set_size(ui->screen_label_cpu_temp, 36, 12);

	//Write style for screen_label_cpu_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_cpu_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_cpu_temp, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_cpu_temp, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_cpu_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_cpu_load
	ui->screen_label_cpu_load = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_cpu_load, "00");
	lv_label_set_long_mode(ui->screen_label_cpu_load, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_cpu_load, 45, 55);
	lv_obj_set_size(ui->screen_label_cpu_load, 36, 12);

	//Write style for screen_label_cpu_load, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_cpu_load, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_cpu_load, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_cpu_load, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_cpu_load, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_cpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_cpu_fan
	ui->screen_label_cpu_fan = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_cpu_fan, "1360");
	lv_label_set_long_mode(ui->screen_label_cpu_fan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_cpu_fan, 40, 80);
	lv_obj_set_size(ui->screen_label_cpu_fan, 36, 12);

	//Write style for screen_label_cpu_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_cpu_fan, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_cpu_fan, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_cpu_fan, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_cpu_fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_cpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_1, "%\n");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 70, 55);
	lv_obj_set_size(ui->screen_label_1, 28, 16);

	//Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_Acme_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_6
	ui->screen_label_6 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_6, "'C");
	lv_label_set_long_mode(ui->screen_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_6, 70, 30);
	lv_obj_set_size(ui->screen_label_6, 28, 16);

	//Write style for screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_6, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_6, &lv_font_Acme_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_11
	ui->screen_label_11 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_11, "INTEL i5-13600KF");
	lv_label_set_long_mode(ui->screen_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_11, 20, 8);
	lv_obj_set_size(ui->screen_label_11, 90, 10);

	//Write style for screen_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_11, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_11, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_11, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_13
	ui->screen_label_13 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_13, "RPM");
	lv_label_set_long_mode(ui->screen_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_13, 74, 80);
	lv_obj_set_size(ui->screen_label_13, 35, 16);

	//Write style for screen_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_13, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_13, &lv_font_Acme_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_14
	ui->screen_label_14 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_14, "Temp");
	lv_label_set_long_mode(ui->screen_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_14, 5, 30);
	lv_obj_set_size(ui->screen_label_14, 40, 12);

	//Write style for screen_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_14, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_14, &lv_font_Alatsi_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_14, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_15
	ui->screen_label_15 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_15, "Load");
	lv_label_set_long_mode(ui->screen_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_15, 5, 55);
	lv_obj_set_size(ui->screen_label_15, 40, 12);

	//Write style for screen_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_15, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_15, &lv_font_Acme_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_15, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_15, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_16
	ui->screen_label_16 = lv_label_create(ui->screen_left);
	lv_label_set_text(ui->screen_label_16, "Fan\n");
	lv_label_set_long_mode(ui->screen_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_16, 5, 80);
	lv_obj_set_size(ui->screen_label_16, 40, 12);

	//Write style for screen_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_16, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_16, &lv_font_Acme_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_16, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen_left);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1, &_cpu_alpha_16x16);
	lv_img_set_pivot(ui->screen_img_1, 50,50);
	lv_img_set_angle(ui->screen_img_1, 0);
	lv_obj_set_pos(ui->screen_img_1, 2, 5);
	lv_obj_set_size(ui->screen_img_1, 16, 16);

	//Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_animimg_spaceman
	ui->screen_animimg_spaceman = lv_animimg_create(ui->screen_left);
	lv_animimg_set_src(ui->screen_animimg_spaceman, (const void **) screen_animimg_spaceman_imgs, 17);
	lv_animimg_set_duration(ui->screen_animimg_spaceman, 30*17);
	lv_animimg_set_repeat_count(ui->screen_animimg_spaceman, LV_ANIM_REPEAT_INFINITE);
	lv_animimg_start(ui->screen_animimg_spaceman);
	lv_obj_set_pos(ui->screen_animimg_spaceman, 25, 105);
	lv_obj_set_size(ui->screen_animimg_spaceman, 60, 60);

	//Write codes screen_right
	ui->screen_right = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_right, 125, 5);
	lv_obj_set_size(ui->screen_right, 190, 230);
	lv_obj_set_scrollbar_mode(ui->screen_right, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_right, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_right, lv_color_hex(0x848284), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_right, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_right, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_2
	ui->screen_img_2 = lv_img_create(ui->screen_right);
	lv_obj_add_flag(ui->screen_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_2, &_gpu_alpha_16x16);
	lv_img_set_pivot(ui->screen_img_2, 50,50);
	lv_img_set_angle(ui->screen_img_2, 0);
	lv_obj_set_pos(ui->screen_img_2, 5, 5);
	lv_obj_set_size(ui->screen_img_2, 16, 16);

	//Write style for screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_3
	ui->screen_img_3 = lv_img_create(ui->screen_right);
	lv_obj_add_flag(ui->screen_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_3, &_temp_alpha_12x12);
	lv_img_set_pivot(ui->screen_img_3, 50,50);
	lv_img_set_angle(ui->screen_img_3, 0);
	lv_obj_set_pos(ui->screen_img_3, 44, 84);
	lv_obj_set_size(ui->screen_img_3, 12, 12);

	//Write style for screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_temp
	ui->screen_label_temp = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_temp, "Temp");
	lv_label_set_long_mode(ui->screen_label_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_temp, 55, 87);
	lv_obj_set_size(ui->screen_label_temp, 36, 10);

	//Write style for screen_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_temp, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_temp, &lv_font_Acme_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_temp, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_load
	ui->screen_label_load = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_load, "Load\n");
	lv_label_set_long_mode(ui->screen_label_load, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_load, 142, 87);
	lv_obj_set_size(ui->screen_label_load, 36, 10);

	//Write style for screen_label_load, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_load, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_load, &lv_font_Acme_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_load, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_load, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arc_gpu_temp
	ui->screen_arc_gpu_temp = lv_arc_create(ui->screen_right);
	lv_arc_set_mode(ui->screen_arc_gpu_temp, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->screen_arc_gpu_temp, 0, 100);
	lv_arc_set_bg_angles(ui->screen_arc_gpu_temp, 0, 270);
	lv_arc_set_angles(ui->screen_arc_gpu_temp, 0, 10);
	lv_arc_set_rotation(ui->screen_arc_gpu_temp, 90);
	lv_obj_set_style_arc_rounded(ui->screen_arc_gpu_temp, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_arc_gpu_temp, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arc_gpu_temp, 10, 30);
	lv_obj_set_size(ui->screen_arc_gpu_temp, 80, 80);

	//Write style for screen_arc_gpu_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_arc_gpu_temp, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_gpu_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_gpu_temp, lv_color_hex(0x313431), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arc_gpu_temp, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arc_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arc_gpu_temp, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_arc_gpu_temp, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_gpu_temp, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_gpu_temp, lv_color_hex(0xff6500), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_arc_gpu_temp, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_gpu_temp, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_arc_gpu_temp, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_arc_gpu_load
	ui->screen_arc_gpu_load = lv_arc_create(ui->screen_right);
	lv_arc_set_mode(ui->screen_arc_gpu_load, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->screen_arc_gpu_load, 0, 100);
	lv_arc_set_bg_angles(ui->screen_arc_gpu_load, 0, 270);
	lv_arc_set_angles(ui->screen_arc_gpu_load, 0, 10);
	lv_arc_set_rotation(ui->screen_arc_gpu_load, 90);
	lv_obj_set_style_arc_rounded(ui->screen_arc_gpu_load, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_arc_gpu_load, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arc_gpu_load, 100, 30);
	lv_obj_set_size(ui->screen_arc_gpu_load, 80, 80);

	//Write style for screen_arc_gpu_load, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_arc_gpu_load, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_gpu_load, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_gpu_load, lv_color_hex(0x313431), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arc_gpu_load, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arc_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arc_gpu_load, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_arc_gpu_load, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_gpu_load, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_gpu_load, lv_color_hex(0xff6500), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_arc_gpu_load, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_gpu_load, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_arc_gpu_load, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_bar_gpu_fan
	ui->screen_bar_gpu_fan = lv_bar_create(ui->screen_right);
	lv_obj_set_style_anim_time(ui->screen_bar_gpu_fan, 1000, 0);
	lv_bar_set_mode(ui->screen_bar_gpu_fan, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screen_bar_gpu_fan, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_bar_gpu_fan, 50, 135);
	lv_obj_set_size(ui->screen_bar_gpu_fan, 80, 12);

	//Write style for screen_bar_gpu_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_gpu_fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_gpu_fan, lv_color_hex(0x313431), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_gpu_fan, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bar_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bar_gpu_fan, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_gpu_fan, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_gpu_fan, lv_color_hex(0xff6500), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_gpu_fan, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_bar_gpu_vol
	ui->screen_bar_gpu_vol = lv_bar_create(ui->screen_right);
	lv_obj_set_style_anim_time(ui->screen_bar_gpu_vol, 1000, 0);
	lv_bar_set_mode(ui->screen_bar_gpu_vol, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screen_bar_gpu_vol, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_bar_gpu_vol, 50, 163);
	lv_obj_set_size(ui->screen_bar_gpu_vol, 80, 12);

	//Write style for screen_bar_gpu_vol, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_gpu_vol, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_gpu_vol, lv_color_hex(0x313431), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_gpu_vol, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bar_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bar_gpu_vol, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_gpu_vol, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_gpu_vol, lv_color_hex(0xff6500), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_gpu_vol, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_bar_gpu_watt
	ui->screen_bar_gpu_watt = lv_bar_create(ui->screen_right);
	lv_obj_set_style_anim_time(ui->screen_bar_gpu_watt, 1000, 0);
	lv_bar_set_mode(ui->screen_bar_gpu_watt, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screen_bar_gpu_watt, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_bar_gpu_watt, 50, 191);
	lv_obj_set_size(ui->screen_bar_gpu_watt, 80, 12);

	//Write style for screen_bar_gpu_watt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_gpu_watt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_gpu_watt, lv_color_hex(0x313431), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_gpu_watt, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bar_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bar_gpu_watt, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_gpu_watt, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_gpu_watt, lv_color_hex(0xff6500), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_gpu_watt, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_label_gpu_load
	ui->screen_label_gpu_load = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_gpu_load, "00");
	lv_label_set_long_mode(ui->screen_label_gpu_load, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_gpu_load, 118, 58);
	lv_obj_set_size(ui->screen_label_gpu_load, 28, 16);

	//Write style for screen_label_gpu_load, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_gpu_load, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_gpu_load, &lv_font_Acme_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_gpu_load, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_gpu_load, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_gpu_load, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_gpu_temp
	ui->screen_label_gpu_temp = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_gpu_temp, "00");
	lv_label_set_long_mode(ui->screen_label_gpu_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_gpu_temp, 30, 58);
	lv_obj_set_size(ui->screen_label_gpu_temp, 28, 16);

	//Write style for screen_label_gpu_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_gpu_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_gpu_temp, &lv_font_Acme_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_gpu_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_gpu_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_gpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_gpu_vol
	ui->screen_label_gpu_vol = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_gpu_vol, "0.66");
	lv_label_set_long_mode(ui->screen_label_gpu_vol, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_gpu_vol, 132, 163);
	lv_obj_set_size(ui->screen_label_gpu_vol, 36, 12);

	//Write style for screen_label_gpu_vol, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_gpu_vol, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_gpu_vol, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_gpu_vol, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_gpu_vol, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_gpu_vol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_gpu_watt
	ui->screen_label_gpu_watt = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_gpu_watt, "13.6");
	lv_label_set_long_mode(ui->screen_label_gpu_watt, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_gpu_watt, 132, 191);
	lv_obj_set_size(ui->screen_label_gpu_watt, 36, 12);

	//Write style for screen_label_gpu_watt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_gpu_watt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_gpu_watt, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_gpu_watt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_gpu_watt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_gpu_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_gpu_fan
	ui->screen_label_gpu_fan = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_gpu_fan, "30");
	lv_label_set_long_mode(ui->screen_label_gpu_fan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_gpu_fan, 132, 135);
	lv_obj_set_size(ui->screen_label_gpu_fan, 36, 12);

	//Write style for screen_label_gpu_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_gpu_fan, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_gpu_fan, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_gpu_fan, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_gpu_fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_gpu_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_load
	ui->screen_img_load = lv_img_create(ui->screen_right);
	lv_obj_add_flag(ui->screen_img_load, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_load, &_load_alpha_12x12);
	lv_img_set_pivot(ui->screen_img_load, 50,50);
	lv_img_set_angle(ui->screen_img_load, 0);
	lv_obj_set_pos(ui->screen_img_load, 130, 86);
	lv_obj_set_size(ui->screen_img_load, 12, 12);

	//Write style for screen_img_load, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_load, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_3, "%\n");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_3, 142, 58);
	lv_obj_set_size(ui->screen_label_3, 28, 16);

	//Write style for screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_3, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_3, &lv_font_Acme_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_7
	ui->screen_label_7 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_7, "'C");
	lv_label_set_long_mode(ui->screen_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_7, 52, 58);
	lv_obj_set_size(ui->screen_label_7, 28, 16);

	//Write style for screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_7, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_7, &lv_font_Acme_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_17
	ui->screen_label_17 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_17, "Fan\n");
	lv_label_set_long_mode(ui->screen_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_17, 20, 135);
	lv_obj_set_size(ui->screen_label_17, 40, 12);

	//Write style for screen_label_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_17, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_17, &lv_font_Acme_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_17, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_17, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_10
	ui->screen_label_10 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_10, "NVIDIA GeForce RTX 4060TI");
	lv_label_set_long_mode(ui->screen_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_10, 25, 8);
	lv_obj_set_size(ui->screen_label_10, 150, 10);

	//Write style for screen_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_10, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_10, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_18
	ui->screen_label_18 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_18, "Vol");
	lv_label_set_long_mode(ui->screen_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_18, 21, 163);
	lv_obj_set_size(ui->screen_label_18, 40, 12);

	//Write style for screen_label_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_18, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_18, &lv_font_Acme_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_18, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_18, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_19
	ui->screen_label_19 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_19, "Watt\n");
	lv_label_set_long_mode(ui->screen_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_19, 12, 191);
	lv_obj_set_size(ui->screen_label_19, 40, 12);

	//Write style for screen_label_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_19, lv_color_hex(0x6b6d73), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_19, &lv_font_Acme_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_19, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_19, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_23
	ui->screen_label_23 = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_23, "%");
	lv_label_set_long_mode(ui->screen_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_23, 164, 133);
	lv_obj_set_size(ui->screen_label_23, 20, 16);

	//Write style for screen_label_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_23, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_23, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_23, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_23, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_V
	ui->screen_label_V = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_V, "V");
	lv_label_set_long_mode(ui->screen_label_V, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_V, 164, 160);
	lv_obj_set_size(ui->screen_label_V, 20, 16);

	//Write style for screen_label_V, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_V, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_V, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_V, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_V, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_W
	ui->screen_label_W = lv_label_create(ui->screen_right);
	lv_label_set_text(ui->screen_label_W, "W");
	lv_label_set_long_mode(ui->screen_label_W, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_W, 164, 190);
	lv_obj_set_size(ui->screen_label_W, 20, 16);

	//Write style for screen_label_W, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_W, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_W, &lv_font_Acme_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_W, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_W, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_W, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);


}
