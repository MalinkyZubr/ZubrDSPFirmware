cmake_minimum_required(VERSION 3.25)

set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(ZubrDSPFirmware CXX C ASM)

pico_sdk_init()

add_executable(main
        $ENV{PROJECT}/src/main.c
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 1)

# pull in common dependencies
target_link_libraries(main
        pico_stdlib
        hardware_uart
        hardware_gpio
        pico_lwip_arch
        pico_cyw43_arch_none
)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(main)
