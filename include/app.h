//
// Created by malinkyzubr on 6/19/25.
//

#ifndef APP_H
#define APP_H

// std
#include <limits.h>

// pico SDK includes
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "bsp/board.h"
#include "hardware/gpio.h"

// tinyusb stuff
#include "tusb.h"
#include "bsp/board_api.h"

// local
#include "dac.h"
#include "usb.h"


typedef enum _ApplicationState {
    MOUNTED = 0,
    UNMOUNDED = 1,
    ERROR = 2,
    PAUSED = 3
} ApplicationState;

typedef enum _ErrorCode {
    OK = 0,
    OVERFLOW = 1,
    UNDERFLOW = 2
} ErrorCode;

typedef struct _ReturnMessage {
    ApplicationState current_state;
    ErrorCode error_state;
    int compute_time;
} ReturnMessage;

void configure_usb_indicators(uint pins[4]);
void update_gpio_indicators(ApplicationState state, uint pins[4]);

ApplicationState next_state_logic(ApplicationState current_state, USBCommand input);
void state_action(ApplicationState current_state, USBManager *usb_manager, DACController *dac_controller);


#endif //APP_H
