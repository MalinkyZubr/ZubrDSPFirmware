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
};

static const struct usb_endpoint_descriptor control_out = {
    .bLength = sizeof(struct usb_endpoint_descriptor),
    .bDescriptorType =                USB_DT_ENDPOINT, // is device
    .bEndpointAddress =                    0b00000000, // the 0th endpoint configured for out direction
    .bmAttributes =                        0b00000000, // control transfer, non-isochronous
    .wMaxPacketSize =              0b0000000000010000, // 30 bit frame -> 4 bytes
    .bInterval =                                    0, // I HAVE NO IDEA YET
};

static const struct usb_interface_descriptor CCIInterface = {
    .bLength = sizeof(struct usb_interface_descriptor),
    .bDescriptorType                = USB_DT_INTERFACE, // is a device interface
    .bInterfaceNumber                              = 0, // control interface
    .bAlternateSetting                             = 0, // irrelevant
    .bNumEndpoints                                 = 0, // Only control endpoints
    .bInterfaceClass                             = 02h, // Communications Device Class
    .bInterfaceSubClass                          = 02h, // Network Control Model
    .bInterfaceProtocol                          = 00h, // irrelevant! Stupid protocols! Haha!
    .iInterface                                    = 0  // No silly strings ANYWHERE
};

// might want alternatives for the containing interface in case high speed not possible?
static const struct usb_endpoint_descriptor data_in = {
    .bLength = sizeof(struct usb_endpoint_descriptor),
    .bDescriptorType =                USB_DT_ENDPOINT, // is device
    .bEndpointAddress =                    0b10000001, // the 1st endpoint configured for IN direction
    .bmAttributes =                        0b00000001, // isochronous, no synchronization
    .wMaxPacketSize =              0b0000010000000000, // 1024 bytes per packet, high speed
    .bInterval =                                    4, // polling period of 8
};

static const struct usb_endpoint_descriptor data_out = {
    .bLength = sizeof(struct usb_endpoint_descriptor),
    .bDescriptorType =                USB_DT_ENDPOINT, // is device
    .bEndpointAddress =                    0b00000001, // the 1st endpoint configured for OUT direction
    .bmAttributes =                        0b00000001, // isochronous, no synchronization
    .wMaxPacketSize =              0b0000010000000000, // 1024 bytes per packet, high speed
    .bInterval =                                    4, // polling period of 8
};

static const struct usb_interface_descriptor DCIInterface = {
    .bLength = sizeof(struct usb_interface_descriptor),
    .bDescriptorType                = USB_DT_INTERFACE, // is a device interface
    .bInterfaceNumber                              = 1, // control interface
    .bAlternateSetting                             = 0, // irrelevant
    .bNumEndpoints                                 = 2, // one in and one out endpoint
    .bInterfaceClass                             = 0Ah, // Communications Device Class
    .bInterfaceSubClass                          = 00h, // Network Control Model
    .bInterfaceProtocol                          = 00h, // irrelevant! Stupid protocols! Haha!
    .iInterface                                    = 0  // No silly strings ANYWHERE
};

static const struct usb_config_descriptor config = {
    .bLength       = sizeof(struct usb_config_descriptor),
    .bDescriptorType               = USB_DT_CONFIGURATION, // is a device
    .wTotalLength = 2 * sizeof(usb_interface_descriptor) +
                      4 * sizeof(usb_endpoint_descriptor), // 2 interfaces, 4 endpoints
    .bNumInterfaces                                   = 2,
    .bConfigurationValue                              = 1,
    .iConfiguration                                   = 0,
    .bmAttributes                            = 0b10000000, // not self powered, no remote wakeup
    .bMaxPower                                      = 150, // 300 ma max current draw of the pico
};

static const struct usb_device_descriptor device = {
    .bLength = sizeof(struct usb_device_descriptor),
    .bDescriptorType                = USB_DT_DEVICE,
    .bcdUSB                                = 0x0110, // usb 1.1
    .bDeviceClass                             = 02h,
    .bDeviceSubClass                          = 02h,
    .bDeviceProtocol                          = 00h,
    .bMaxPacketSize0                           = 64,
    .idVendor                              = 0x0AFE, // CUM(mins engine group:)
    .idProduct                             = 0x6969, // 0x6969: Goober's constant
    .bcdDevice                             = 0x0100,
    .iManufacturer                              = 0,
    .iProduct                                   = 0,
    .iSerialNumber                              = 0,
    .bNumConfigurations                         = 1,
};

#endif