#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "generated/ws2812.pio.h"
#include "LED_controller.h"

#define WS2812_PIN 0
#define NUM_PIXELS 29

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t red, uint8_t green, uint8_t blue) {
    return((uint32_t) (red) << 8 | (uint32_t) (green) << 16) | (uint8_t) (blue);
}

void init_LED() {
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, 1);
}

void cont_light(int len) {
    for(int i=0; i<len; ++i){
        put_pixel(urgb_u32(0xff, 0x61, 0x04)); 
    }
    
}