//
// Created by malinkyzubr on 6/19/25.
//

// pico SDK includes
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "bsp/board.h"

// tinyusb stuff
#include "tusb.h"
#include "bsp/board_api.h"


int main() {
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
    uint pins[4] = {2, 3, 4, 5};
    configure_usb_indicators(pins);

    while (true) {
        for (int x = 0; x < 4; x ++) {
            sleep_ms(1000);
            update_gpio_indicators(x, pins);
        }
    }
}