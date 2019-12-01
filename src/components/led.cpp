#include "led.h"
#include <iostream>

namespace bread {

    LED::LED() {

        setPinCount(2);
    }

    LED::LED(float r, float g, float b) {

        m_r = r;
        m_g = g;
        m_b = b;

        setPinCount(2);
    }

    LED::~LED() {
        //dtor
    }

    void LED::setVoltage(unsigned int pin_id, float voltage, float resistance) {

        if(pin_id == 0) {
            // p_pin

            m_p_pin.m_voltage = voltage;
            m_p_pin.m_resistance = resistance;

            if(voltage > m_n_pin.m_voltage) {
                outputVoltage(1, voltage, resistance);
            }

        } else if (pin_id == 1) {

            m_n_pin.m_voltage = voltage;
            m_n_pin.m_resistance = resistance;

            if(voltage < m_p_pin.m_voltage) {
                outputVoltage(0, voltage, resistance);
            }

        }



    }

    int LED::getStatus() {

        if(m_p_pin.m_voltage - m_n_pin.m_voltage > 2) {

            if(m_n_pin.m_resistance != -1) { // connected

                std::cout << "LED ON: " << m_r << " " << m_g << " " << m_b << "\n";
                return 1;
            }

        }

        std::cout << "LED OFF: " << m_r << " " << m_g << " " << m_b << "\n";

        return 0;
    }

} // bread
