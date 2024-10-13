// Copyright 2024 Reece King (@kingmercian)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"


#ifdef OLED_ENABLE
static uint32_t oled_logo_timer = 0;
static bool clear_logo = true;
static const char logo [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xe8, 0x08, 
    0x10, 0x10, 0x24, 0x20, 0x40, 0x40, 0xd2, 0x80, 0x00, 0x30, 0x00, 0x80, 0x94, 0x89, 0x80, 0x40, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x0f, 
    0x70, 0x80, 0x00, 0x00, 0x00, 0x20, 0x08, 0x04, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x8c, 0x31, 
    0xc1, 0x01, 0x00, 0x00, 0x10, 0x70, 0xe0, 0xe0, 0xc0, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x85, 0x49, 
    0x31, 0x20, 0x20, 0x00, 0x02, 0x04, 0x88, 0x11, 0x33, 0x62, 0xc1, 0x80, 0x71, 0xe0, 0xc0, 0x80, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x58, 0x30, 
    0x10, 0x08, 0x04, 0x04, 0xc4, 0x64, 0x34, 0x14, 0x0a, 0x80, 0x40, 0x21, 0x10, 0x20, 0xc3, 0x40, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 
    0x00, 0x04, 0x22, 0x41, 0x40, 0x40, 0x20, 0x40, 0x81, 0x80, 0x40, 0x20, 0x18, 0x03, 0x08, 0x00, 
    0xf0, 0xf0, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x00, 0x00, 0x10, 0x10, 0xf0, 0xf0, 0x10, 0x10, 0x10, 
    0xf0, 0xf0, 0xc0, 0x80, 0x00, 0xf0, 0xf0, 0x00, 0xc0, 0xe0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x00, 
    0x0f, 0x0f, 0x01, 0x03, 0x0e, 0x0c, 0x08, 0x00, 0x00, 0x08, 0xc8, 0x2f, 0x2f, 0x28, 0x28, 0x08, 
    0xcf, 0x2f, 0x21, 0x23, 0x27, 0xcf, 0x0f, 0x00, 0x03, 0x0f, 0x0c, 0x08, 0x09, 0x0f, 0x0f, 0x00, 
    0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x40, 0x43, 0x42, 0x42, 0x22, 0x1c, 0x00, 
    0x39, 0x26, 0x42, 0x42, 0x26, 0x39, 0x00, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 
    0x10, 0x10, 0xf0, 0x80, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04, 0x04, 0x06, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0xf0, 0x8f, 0x80, 0xa0, 0x08, 0x40, 0x40, 0x40, 0x09, 0x20, 0x24, 0x60, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0x70, 0x00, 0x80, 0xe0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x90, 0x0c, 0x02, 0x49, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0c, 0x02, 0x05, 0x89, 0x8f, 0x07, 0x07, 0xf3, 0xc1, 0x10, 0x7e, 0x0f, 0x01, 0x00, 
    0x00, 0x00, 0x80, 0x20, 0x00, 0x11, 0x11, 0x22, 0xe2, 0x94, 0x9d, 0x48, 0x00, 0x00, 0x00, 0x00, 
    0x08, 0x1f, 0x3f, 0x02, 0x0c, 0x1f, 0x01, 0x03, 0x06, 0x8f, 0x01, 0x40, 0x20, 0x00, 0x10, 0x90, 
    0x30, 0x06, 0x00, 0x80, 0x60, 0x10, 0x00, 0x02, 0x01, 0x00, 0x00, 0x01, 0x62, 0x9c, 0x00, 0x00, 
    0x04, 0x18, 0x88, 0x10, 0x70, 0x00, 0x3c, 0x42, 0x81, 0x80, 0x80, 0x80, 0x60, 0x2c, 0x46, 0xc7, 
    0xc4, 0x86, 0x83, 0x01, 0x18, 0x2c, 0xc4, 0xc2, 0xa1, 0x60, 0x30, 0x50, 0x08, 0x0b, 0x00, 0x00, 
    0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 
    0x0b, 0x0c, 0x08, 0x01, 0x01, 0x03, 0x05, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_left())
    return OLED_ROTATION_270;
  return rotation;
}

void init_timer(void){
   oled_logo_timer = timer_read32();
};

void render_logo(void) {
    oled_write_raw_P(logo, sizeof(logo));
}

void clear_screen(void) {
    if (clear_logo){
      for (uint8_t i = 0; i < OLED_DISPLAY_HEIGHT; ++i) {
        for (uint8_t j = 0; j < OLED_DISPLAY_WIDTH; ++j) {
          oled_write_raw_byte(0x0, i*OLED_DISPLAY_WIDTH + j);
        }
      }
      clear_logo = false;
    }
}

bool oled_task_kb(void) {
    //if (!oled_task_user()) { return false; }
    if ((timer_elapsed32(oled_logo_timer) < SHOW_LOGO)){
        render_logo();
    } else{
        clear_screen();
        oled_task_user();
        }
    return false;
}

#endif

#ifdef RGB_MATRIX_ENABLE
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}
#endif
