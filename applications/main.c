/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 * Copyright (c) 2019-2020, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-10-24     Magicoe      first version
 * 2020-01-10     Kevin/Karl   Add PS demo
 * 2020-09-21     supperthomas fix the main.c
 *
 */

#include <rtdevice.h>
#include <rtthread.h>
#include "drv_pin.h"

#include <lvgl.h>
#include "lv_arc.h"
#include "lv_demo_benchmark.h"
#include "lv_demo_widgets.h"
#include "gui_guider.h"
#include "custom.h"

#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_smartdma.h"
#include "fsl_inputmux_connections.h"
#include "fsl_inputmux.h"
#include "lv_label.h"

#define LEDB_PIN        ((1*32)+2)
#define BUTTON_PIN      ((0*32)+23)

typedef struct
{
    uint16_t cpu_usage;
    uint16_t mem_usage;
    uint16_t gpu_usage;
    uint16_t cpu_freq;
    uint16_t cpu_temperature;
    uint16_t gpu_temperature;
    uint16_t board_temperature;
} monitor_info_u16_t;

typedef struct {
    uint16_t wYear;
    uint16_t wMonth;
    uint16_t wDayOfWeek;
    uint16_t wDay;
    uint16_t wHour;
    uint16_t wMinute;
    uint16_t wSecond;
    uint16_t wMilliseconds;
} mytime_t;

/* 消息队列控制块 */
extern struct rt_messagequeue usb_mq;
lv_ui guider_ui;

static void sw_pin_cb(void *args);

void lv_user_gui_init(void) {
    // lv_demo_benchmark();
    // lv_demo_widgets();
    setup_ui(&guider_ui);
	custom_init(&guider_ui);
}

static void BOARD_InitSmartDMA(void)
{
    RESET_ClearPeripheralReset(kMUX_RST_SHIFT_RSTn);

    INPUTMUX_Init(INPUTMUX0);
    INPUTMUX_AttachSignal(INPUTMUX0, 0, kINPUTMUX_FlexioToSmartDma);

    /* Turnoff clock to inputmux to save power. Clock is only needed to make changes */
    INPUTMUX_Deinit(INPUTMUX0);

    SMARTDMA_InitWithoutFirmware();

    NVIC_EnableIRQ(SMARTDMA_IRQn);
    NVIC_SetPriority(SMARTDMA_IRQn, 3);
}

int main(void)
{
    /* attach FRO 12M to FLEXCOMM2 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);

    CLOCK_SetClkDiv(kCLOCK_DivFlexioClk, 1u);
    CLOCK_AttachClk(kPLL0_to_FLEXIO);
    BOARD_InitSmartDMA();

#if defined(__CC_ARM)
    rt_kprintf("using armcc, version: %d\n", __ARMCC_VERSION);
#elif defined(__clang__)
    rt_kprintf("using armclang, version: %d\n", __ARMCC_VERSION);
#elif defined(__ICCARM__)
    rt_kprintf("using iccarm, version: %d\n", __VER__);
#elif defined(__GNUC__)
    rt_kprintf("using gcc, version: %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

    rt_pin_mode(LEDB_PIN, PIN_MODE_OUTPUT);  /* Set GPIO as Output */

    rt_pin_mode(BUTTON_PIN, PIN_MODE_INPUT_PULLUP);
    rt_pin_attach_irq(BUTTON_PIN, PIN_IRQ_MODE_FALLING, sw_pin_cb, RT_NULL);
    rt_pin_irq_enable(BUTTON_PIN, 1);

    rt_kprintf("MCXN947 HelloWorld\r\n");


#ifdef RT_USING_SDIO
    rt_thread_mdelay(2000);
    if (dfs_mount("sd", "/", "elm", 0, NULL) == 0)
    {
        rt_kprintf("sd mounted to /\n");
    }
    else
    {
        rt_kprintf("sd mount to / failed\n");
    }
#endif
    uint8_t read_buffer[128];

    while (1)
    {
        // rt_pin_write(LEDB_PIN, PIN_HIGH);    /* Set GPIO output 1 */
        // rt_thread_mdelay(500);               /* Delay 500mS */
        // rt_pin_write(LEDB_PIN, PIN_LOW);     /* Set GPIO output 0 */
        // rt_thread_mdelay(500);               /* Delay 500mS */

        /* 从消息队列中接收消息 */
        if (rt_mq_recv(&usb_mq, read_buffer, 34, RT_WAITING_FOREVER) > 0)
        {
            mytime_t* p_time_u16 = (mytime_t*)(read_buffer + 2);
            monitor_info_u16_t* p_info_u16 = (monitor_info_u16_t *)(read_buffer + 2 + sizeof(mytime_t));

            rt_kprintf("wYear         %u\r\n", p_time_u16->wYear);
            rt_kprintf("wMonth        %u\r\n", p_time_u16->wMonth);
            rt_kprintf("wDayOfWeek    %u\r\n", p_time_u16->wDayOfWeek);
            rt_kprintf("wDay          %u\r\n", p_time_u16->wDay);
            rt_kprintf("wHour         %u\r\n", p_time_u16->wHour);
            rt_kprintf("wMinute       %u\r\n", p_time_u16->wMinute);
            rt_kprintf("wSecond       %u\r\n", p_time_u16->wSecond);
            rt_kprintf("wMilliseconds %u\r\n", p_time_u16->wMilliseconds);

            rt_kprintf("cpu_usage         %u\r\n", p_info_u16->cpu_usage);
            rt_kprintf("mem_usage         %u\r\n", p_info_u16->mem_usage);
            rt_kprintf("gpu_usage         %u\r\n", p_info_u16->gpu_usage);
            rt_kprintf("cpu_freq          %u\r\n", p_info_u16->cpu_freq);
            rt_kprintf("cpu_temperature   %u\r\n", p_info_u16->cpu_temperature);
            rt_kprintf("gpu_temperature   %u\r\n", p_info_u16->gpu_temperature);
            rt_kprintf("board_temperature %u\r\n", p_info_u16->board_temperature);

            lv_label_set_text_fmt(guider_ui.screen_label_cpu_temp, "%2d", p_info_u16->cpu_temperature);
            lv_label_set_text_fmt(guider_ui.screen_label_gpu_temp, "%2d", p_info_u16->gpu_temperature);

            lv_label_set_text_fmt(guider_ui.screen_label_cpu_load, "%2d", p_info_u16->cpu_usage);
            lv_label_set_text_fmt(guider_ui.screen_label_gpu_load, "%2d", p_info_u16->gpu_usage);

            lv_arc_set_value(guider_ui.screen_arc_gpu_load, p_info_u16->gpu_usage);
            lv_arc_set_value(guider_ui.screen_arc_gpu_temp, p_info_u16->gpu_temperature);

            lv_label_set_text_fmt(guider_ui.screen_time, "%02d:%02d", p_time_u16->wHour, p_time_u16->wMinute);
            lv_label_set_text_fmt(guider_ui.screen_date, "%02d.%02d.%02d", p_time_u16->wYear, p_time_u16->wMonth, p_time_u16->wDay);
        }
    }
}

static void sw_pin_cb(void *args)
{
    rt_kprintf("sw pressed\r\n");
}

// end file
