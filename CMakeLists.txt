cmake_minimum_required(VERSION 3.25)

set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(ZubrDSPFirmware CXX C ASM)

pico_sdk_init()

add_executable(main
        $ENV{PROJECT}/src/main.c
        $ENV{PROJECT}/src/indicator.c
        $ENV{PROJECT}/src/usb_descriptors.c
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 1)

target_include_directories(main PRIVATE
        $ENV{PROJECT}/include/app.h
        $ENV{PROJECT}/include/dac.h
        $ENV{PROJECT}/include/usb.h
        $ENV{PROJECT}/include/usb_config.h
)

# pull in common dependencies
target_link_libraries(main
        pico_stdlib
        hardware_uart
        hardware_gpio
        pico_lwip_arch
        pico_cyw43_arch_none
        tinyusb_device
        tinyusb_board
)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(main)
