/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_lpi2c.h"
#include "fsl_ft5406_rt.h"

typedef struct _ft5406_rt_touch_point
{
    uint8_t XH;
    uint8_t XL;
    uint8_t YH;
    uint8_t YL;
    uint8_t RESERVED[2];
} ft5406_rt_touch_point_t;

typedef struct _ft5406_rt_touch_data
{
    uint8_t GEST_ID;
    uint8_t TD_STATUS;
    ft5406_rt_touch_point_t TOUCH[FT5406_RT_MAX_TOUCHES];
} ft5406_rt_touch_data_t;

#define TOUCH_POINT_GET_EVENT(T) ((T).XH >> 6U)
#define TOUCH_POINT_GET_ID(T)    ((T).YH >> 4U)
#define TOUCH_POINT_GET_X(T)     ((((uint16_t)(T).XH & 0x0fU) << 8U) | (T).XL)
#define TOUCH_POINT_GET_Y(T)     ((((uint16_t)(T).YH & 0x0fU) << 8U) | (T).YL)

static status_t FT5406_RT_ReadTouchData(ft5406_rt_handle_t *handle);

status_t FT5406_RT_Init(ft5406_rt_handle_t *handle, LPI2C_Type *base)
{
    lpi2c_master_transfer_t *xfer = &(handle->xfer);
    status_t status;
    uint8_t mode;

    if ((NULL == handle) || (NULL == base))
    {
        return kStatus_InvalidArgument;
    }

    handle->base = base;

    /* clear transfer structure and buffer */
    (void)memset(xfer, 0, sizeof(*xfer));
    (void)memset(handle->touch_buf, 0, FT5406_RT_TOUCH_DATA_LEN);

    /* set device mode to normal operation */
    mode                 = 0;
    xfer->slaveAddress   = FT5406_RT_I2C_ADDRESS;
    xfer->direction      = kLPI2C_Write;
    xfer->subaddress     = 0;
    xfer->subaddressSize = 1;
    xfer->data           = &mode;
    xfer->dataSize       = 1;
    xfer->flags          = (uint32_t)kLPI2C_TransferDefaultFlag;

    status = LPI2C_MasterTransferBlocking(handle->base, &handle->xfer);

    /* prepare transfer structure for reading touch data */
    xfer->slaveAddress   = FT5406_RT_I2C_ADDRESS;
    xfer->direction      = kLPI2C_Read;
    xfer->subaddress     = 1;
    xfer->subaddressSize = 1;
    xfer->data           = handle->touch_buf;
    xfer->dataSize       = FT5406_RT_TOUCH_DATA_LEN;
    xfer->flags          = (uint32_t)kLPI2C_TransferDefaultFlag;

    return status;
}

status_t FT5406_RT_Denit(ft5406_rt_handle_t *handle)
{
    if (NULL == handle)
    {
        return kStatus_InvalidArgument;
    }

    handle->base = NULL;
    return kStatus_Success;
}

static status_t FT5406_RT_ReadTouchData(ft5406_rt_handle_t *handle)
{
    if (NULL == handle)
    {
        return kStatus_InvalidArgument;
    }

    return LPI2C_MasterTransferBlocking(handle->base, &handle->xfer);
}

status_t FT5406_RT_GetSingleTouch(ft5406_rt_handle_t *handle, touch_event_t *touch_event, int *touch_x, int *touch_y)
{
    status_t status;
    touch_event_t touch_event_local;

    status = FT5406_RT_ReadTouchData(handle);

    if (status == kStatus_Success)
    {
        ft5406_rt_touch_data_t *touch_data = (ft5406_rt_touch_data_t *)(void *)(handle->touch_buf);

        touch_event_local = (touch_event_t)(uint8_t)TOUCH_POINT_GET_EVENT(touch_data->TOUCH[0]);

        if (touch_event != NULL)
        {
            *touch_event = touch_event_local;
        }

        /* Update coordinates only if there is touch detected */
        if ((touch_event_local == kTouch_Down) || (touch_event_local == kTouch_Contact))
        {
            if (NULL != touch_x)
            {
                // *touch_x = (int)(uint16_t)TOUCH_POINT_GET_X(touch_data->TOUCH[0]);
                *touch_x = (int)(uint16_t)TOUCH_POINT_GET_Y(touch_data->TOUCH[0]);
            }
            if (NULL != touch_y)
            {
                *touch_y = (int)(uint16_t)TOUCH_POINT_GET_Y(touch_data->TOUCH[0]);
                *touch_y = 240 - (int)(uint16_t)TOUCH_POINT_GET_X(touch_data->TOUCH[0]);
            }
        }
    }

    return status;
}

status_t FT5406_RT_GetMultiTouch(ft5406_rt_handle_t *handle,
                                 int *touch_count,
                                 touch_point_t touch_array[FT5406_RT_MAX_TOUCHES])
{
    status_t status;

    status = FT5406_RT_ReadTouchData(handle);

    if (status == kStatus_Success)
    {
        ft5406_rt_touch_data_t *touch_data = (ft5406_rt_touch_data_t *)(void *)(handle->touch_buf);
        unsigned int i;

        /* Check for valid number of touches - otherwise ignore touch information */
        if (touch_data->TD_STATUS > FT5406_RT_MAX_TOUCHES)
        {
            touch_data->TD_STATUS = 0U;
        }

        /* Decode number of touches */
        if (NULL != touch_count)
        {
            *touch_count = (int)touch_data->TD_STATUS;
        }

        /* Decode valid touch points */
        for (i = 0; i < touch_data->TD_STATUS; i++)
        {
            touch_array[i].TOUCH_ID    = TOUCH_POINT_GET_ID(touch_data->TOUCH[i]);
            touch_array[i].TOUCH_EVENT = (touch_event_t)(uint8_t)TOUCH_POINT_GET_EVENT(touch_data->TOUCH[i]);
            touch_array[i].TOUCH_X     = TOUCH_POINT_GET_X(touch_data->TOUCH[i]);
            touch_array[i].TOUCH_Y     = TOUCH_POINT_GET_Y(touch_data->TOUCH[i]);
        }

        /* Clear vacant elements of touch_array */
        for (; i < FT5406_RT_MAX_TOUCHES; i++)
        {
            touch_array[i].TOUCH_ID    = 0;
            touch_array[i].TOUCH_EVENT = kTouch_Reserved;
            touch_array[i].TOUCH_X     = 0;
            touch_array[i].TOUCH_Y     = 0;
        }
    }

    return status;
}
