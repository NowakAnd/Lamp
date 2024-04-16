#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "diagnostic_controller.h"

void initialize_adc_onboard_temp()
{
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
}

float read_onboard_temp(const char unit)
{
    const float conversionFactor = 3.3f / (1 << 12);

    float voltage_read = (float)adc_read() * conversionFactor;
    float tempC = 27.0f - (voltage_read - 0.706f) / 0.001721f;

    if(unit == 'C')
    {
        return tempC;
    }
    else if (unit == 'F')
    {
        return tempC * 9 / 5 + 32;
    }

    return -1.0f;
    
}

void software_reset(){
    *((volatile uint32_t*)(PPB_BASE + 0x0ED0C)) = 0x5FA0004;
}
