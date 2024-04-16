#ifndef DIAGNOSTIC_CONTROLER_H
#define DIAGNOSTIC_CONTROLER_H

/*!
* \brief Initializae ADC temp measurement onboard
*/
void initialize_adc_onboard_temp();

/*!
* \brief Read temperature value of onboard chip
* \param unit "C" for Celcius, "F" for Farenheit
* \return float value of temperature
*/
float read_onboard_temp(const char unit);

/*!
*\brief Perform Software Reset
*/
void software_reset();

#endif