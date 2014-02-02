/******************************************************************************
 *
 *  Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *  Not a Contribution.
 *
 *  Copyright (C) 2009-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  Filename:      userial.h
 *
 *  Description:   Contains definitions used for serial port controls
 *
 ******************************************************************************/

#ifndef USERIAL_H
#define USERIAL_H

/******************************************************************************
**  Constants & Macros
******************************************************************************/

/**** port IDs ****/
#define USERIAL_PORT_1          0
#define USERIAL_PORT_2          1
#define USERIAL_PORT_3          2
#define USERIAL_PORT_4          3
#define USERIAL_PORT_5          4
#define USERIAL_PORT_6          5
#define USERIAL_PORT_7          6
#define USERIAL_PORT_8          7
#define USERIAL_PORT_9          8
#define USERIAL_PORT_10         9
#define USERIAL_PORT_11         10
#define USERIAL_PORT_12         11
#define USERIAL_PORT_13         12
#define USERIAL_PORT_14         13
#define USERIAL_PORT_15         14
#define USERIAL_PORT_16         15
#define USERIAL_PORT_17         16
#define USERIAL_PORT_18         17

typedef enum {
    USERIAL_OP_INIT,
    USERIAL_OP_RXFLOW_ON,
    USERIAL_OP_RXFLOW_OFF,
} userial_ioctl_op_t;

/******************************************************************************
**  Type definitions
******************************************************************************/

/******************************************************************************
**  Extern variables and functions
******************************************************************************/

/******************************************************************************
**  Functions
******************************************************************************/

/*******************************************************************************
**
** Function        userial_init
**
** Description     Initializes the userial driver
**
** Returns         TRUE/FALSE
**
*******************************************************************************/
typedef uint8_t (*tUSERIAL_INIT)(void);

/*******************************************************************************
**
** Function        userial_open
**
** Description     Open Bluetooth device with the port ID
**
** Returns         TRUE/FALSE
**
*******************************************************************************/
typedef uint8_t (*tUSERIAL_OPEN)(uint8_t port);

/*******************************************************************************
**
** Function        userial_read
**
** Description     Read data from the userial port
**
** Returns         Number of bytes actually read from the userial port and
**                 copied into p_data.  This may be less than len.
**
*******************************************************************************/
typedef uint16_t (*tUSERIAL_READ)(uint16_t msg_id, uint8_t *p_buffer, uint16_t len);

/*******************************************************************************
**
** Function        userial_write
**
** Description     Write data to the userial port
**
** Returns         Number of bytes actually written to the userial port. This
**                 may be less than len.
**
*******************************************************************************/
typedef uint16_t (*tUSERIAL_WRITE)(uint16_t msg_id, uint8_t *p_data, uint16_t len);

/*******************************************************************************
**
** Function        userial_close
**
** Description     Close the userial port
**
** Returns         None
**
*******************************************************************************/
typedef void (*tUSERIAL_CLOSE)(void);

/*******************************************************************************
**
** Function        userial_ioctl
**
** Description     ioctl inteface
**
** Returns         None
**
*******************************************************************************/
typedef void (*tUSERIAL_IOCTL)(userial_ioctl_op_t op, void *p_data);

typedef struct {
    tUSERIAL_INIT init;
    tUSERIAL_OPEN open;
    tUSERIAL_READ read;
    tUSERIAL_WRITE write;
    tUSERIAL_CLOSE close;
    tUSERIAL_IOCTL ioctl;
} tUSERIAL_IF;

#ifdef QCOM_WCN_SSR
uint8_t userial_dev_inreset();
#endif

#endif /* USERIAL_H */

