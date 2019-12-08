#include "led.h"
#include <iostream>
#include <rendering/texture_generator.h>

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

                //std::cout << "LED ON: " << m_r << " " << m_g << " " << m_b << "\n";
                return 1;
            }

        }

        //std::cout << "LED OFF: " << m_r << " " << m_g << " " << m_b << "\n";

        return 0;
    }

    undicht::Sprite& LED::getSprite() {

        // updating m_sprite
        if(m_update_sprite) {
            undicht::core::BufferLayout pixel_layout({undicht::core::UND_VEC3F});
            m_sprite.setPixelFormat(pixel_layout);
            m_sprite.setSize(1,1); // texture size
            if(getStatus()) {
                m_sprite.setData(TextureGenerator::to24BitColor(glm::vec3(m_r, m_g, m_b)), 3);
            } else {
                m_sprite.setData(TextureGenerator::to24BitColor(0.3f * glm::vec3(m_r, m_g, m_b)), 3);
            }
            m_sprite.setScale(glm::vec2(0.01,0.01)); // sprite scale
            m_update_sprite = false;
        }

        return m_sprite;
    }

} // bread
