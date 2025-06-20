//
// Created by malinkyzubr on 6/20/25.
//

#ifndef USB_CONFIG_H
#define USB_CONFIG_H

#include "usb_common.h"


static const struct usb_endpoint_descriptor control_in = {
    .bLength = sizeof(struct usb_endpoint_descriptor),
    .bDescriptorType =                USB_DT_ENDPOINT, // is device
    .bEndpointAddress =                    0b10000000, // the 0th endpoint configured for IN direction
    .bmAttributes =                        0b00000000, // control transfer, non-isochronous
    .wMaxPacketSize =              0b0000000000010000, // 40 bit frame -> 6 bytes
    .bInterval =                                    0, // I HAVE NO IDEA YET
}

static const struct usb_endpoint_descriptor control_out = {
    .bLength = sizeof(struct usb_endpoint_descriptor),
    .bDescriptorType =                USB_DT_ENDPOINT, // is device
    .bEndpointAddress =                    0b00000000, // the 0th endpoint configured for out direction
    .bmAttributes =                        0b00000000, // control transfer, non-isochronous
    .wMaxPacketSize =              0b0000000000010000, // 30 bit frame -> 4 bytes
    .bInterval =                                    0, // I HAVE NO IDEA YET
}


#endif