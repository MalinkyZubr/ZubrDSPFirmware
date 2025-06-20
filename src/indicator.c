//
// Created by malinkyzubr on 6/19/25.
//


#include "../include/app.h"


void configure_usb_indicators(uint pins[4]) {
    for (int index = 0; index < 4; index++) {
        gpio_init(pins[index]);
        gpio_set_dir(pins[index], GPIO_OUT);
    }
}

void update_gpio_indicators(ApplicationState state, uint pins[4]) {
    for (int index = 0; index < 4; index++) {
        gpio_clr_mask(1 << pins[index]);
    }

    gpio_set_mask(1 << pins[state]);
}