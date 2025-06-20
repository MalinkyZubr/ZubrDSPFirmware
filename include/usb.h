//
// Created by malinkyzubr on 6/19/25.
//

#ifndef USB_H
#define USB_H

// pico SDK includes
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "bsp/board.h"
#include "hardware/gpio.h"

// tinyusb stuff
#include "tusb.h"
#include "bsp/board_api.h"


typedef enum _USBCommand {
    START = 0,
    STOP = 1,
    PAUSE = 2,
} USBCommand;

typedef struct _USBManager {} USBManager;

#endif USB_H
