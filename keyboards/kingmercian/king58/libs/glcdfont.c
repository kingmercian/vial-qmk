// Copyright 2024 Reece King (@kingmercian)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "progmem.h"

static const unsigned char PROGMEM font[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x28, 0x7c, 0x28, 0x7c, 0x28, 0x00,
    0x5c, 0x54, 0xfe, 0x54, 0x74, 0x00,
    0x44, 0x20, 0x10, 0x08, 0x44, 0x00,
    0x28, 0x54, 0x54, 0x20, 0x50, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x38, 0x44, 0x00, 0x00, 0x00, 0x00,
    0x44, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x07, 0x02, 0x00, 0x00, 0x00,
    0x10, 0x10, 0x7c, 0x10, 0x10, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x60, 0x10, 0x0c, 0x00, 0x00, 0x00,
    0x7c, 0x64, 0x54, 0x4c, 0x7c, 0x00,
    0x48, 0x7c, 0x40, 0x00, 0x00, 0x00,
    0x64, 0x54, 0x54, 0x54, 0x48, 0x00,
    0x44, 0x54, 0x54, 0x54, 0x6c, 0x00,
    0x3c, 0x20, 0x70, 0x20, 0x20, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x24, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x74, 0x00,
    0x04, 0x04, 0x64, 0x14, 0x0c, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x7c, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x7c, 0x00,
    0x44, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x28, 0x44, 0x00, 0x00, 0x00,
    0x28, 0x28, 0x28, 0x28, 0x28, 0x00,
    0x44, 0x28, 0x10, 0x00, 0x00, 0x00,
    0x08, 0x04, 0x54, 0x08, 0x00, 0x00,
    0x7c, 0x44, 0x54, 0x54, 0x5c, 0x00,
    0x7c, 0x24, 0x24, 0x24, 0x7c, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x6c, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x44, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x44, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x04, 0x00,
    0x7c, 0x44, 0x44, 0x54, 0x74, 0x00,
    0x7c, 0x10, 0x10, 0x10, 0x7c, 0x00,
    0x44, 0x44, 0x7c, 0x44, 0x44, 0x00,
    0x60, 0x40, 0x40, 0x44, 0x7c, 0x00,
    0x7c, 0x10, 0x10, 0x28, 0x44, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x7c, 0x08, 0x10, 0x08, 0x7c, 0x00,
    0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00,
    0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x08, 0x00,
    0x3c, 0x24, 0x64, 0x24, 0x3c, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x68, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x74, 0x00,
    0x04, 0x04, 0x7c, 0x04, 0x04, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x7c, 0x00,
    0x0c, 0x30, 0x40, 0x30, 0x0c, 0x00,
    0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00,
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
    0x0c, 0x10, 0x60, 0x10, 0x0c, 0x00,
    0x44, 0x64, 0x54, 0x4c, 0x44, 0x00,
    0x7c, 0x44, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x10, 0x60, 0x00, 0x00, 0x00,
    0x44, 0x7c, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x00,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x24, 0x24, 0x24, 0x7c, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x6c, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x44, 0x00,
    0x7c, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x54, 0x54, 0x54, 0x44, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x04, 0x00,
    0x7c, 0x44, 0x44, 0x54, 0x74, 0x00,
    0x7c, 0x10, 0x10, 0x10, 0x7c, 0x00,
    0x44, 0x44, 0x7c, 0x44, 0x44, 0x00,
    0x60, 0x40, 0x40, 0x44, 0x7c, 0x00,
    0x7c, 0x10, 0x10, 0x28, 0x44, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x7c, 0x08, 0x10, 0x08, 0x7c, 0x00,
    0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00,
    0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x08, 0x00,
    0x3c, 0x24, 0x64, 0x24, 0x3c, 0x00,
    0x7c, 0x14, 0x14, 0x14, 0x68, 0x00,
    0x5c, 0x54, 0x54, 0x54, 0x74, 0x00,
    0x04, 0x04, 0x7c, 0x04, 0x04, 0x00,
    0x7c, 0x40, 0x40, 0x40, 0x7c, 0x00,
    0x0c, 0x30, 0x40, 0x30, 0x0c, 0x00,
    0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00,
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
    0x0c, 0x10, 0x60, 0x10, 0x0c, 0x00,
    0x44, 0x64, 0x54, 0x4c, 0x44, 0x00,
    0x10, 0x7c, 0x44, 0x00, 0x00, 0x00,
    0x6c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x44, 0x7c, 0x10, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x02, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
