// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 150U

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN GP3
#define I2C1_SDA_PIN GP2
#define OLED_DISPLAY_ADDRESS 0x3D

#define OLED_DISPLAY_128X64 




// RGB Matrix
// The pin connected to the data pin of the LEDs
// The number of LEDs connected

