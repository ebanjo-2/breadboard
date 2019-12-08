#include "breadboard.h"
#include <iostream>
#include <rendering/board_texture.h>

namespace bread {

    Breadboard::Breadboard() {
        //ctor
    }

    Breadboard::~Breadboard() {
        //dtor
    }

    void Breadboard::initialize(int width, int height) {
        /** @param width and height describing the number of contacts in the main area */

        m_width = width;
        m_height = height;

        m_positive_power_bus.setSize(width);
        m_negative_power_bus.setSize(width);

        // initializing the main area
        for(int i = 0; i < height; i++) {

            // the main area is divided into two halves with one power bus on each side
            m_terminal_strips.emplace_back(ContactStrip(height / 2));

        }


    }

    void Breadboard::getSize(int& width, int& height) {

        width = m_width;
        height = m_height;
    }


    /** @return all components connected to the board */
    std::vector<Component*> Breadboard::getComponents() {

        std::vector<Component*> components;

        // for the power busses
        for(int i = 0; i < m_positive_power_bus.m_components.size(); i++) {

            if(m_positive_power_bus.m_components.at(i) && (!m_positive_power_bus.m_pin_ids.at(i))) {
                // pin 0 of some component
                components.push_back(m_positive_power_bus.m_components.at(i));
            }
        }

        for(int i = 0; i < m_negative_power_bus.m_components.size(); i++) {

            if(m_negative_power_bus.m_components.at(i) && (!m_negative_power_bus.m_pin_ids.at(i))) {
                // pin 0 of some component
                components.push_back(m_negative_power_bus.m_components.at(i));
            }
        }


        // for the terminal area
        for(ContactStrip& contact : m_terminal_strips) {

            for(int i = 0; i < contact.m_components.size(); i++) {

                if(contact.m_components.at(i) && (!contact.m_pin_ids.at(i))) {
                    // pin 0 of some component
                    components.push_back(contact.m_components.at(i));
                }
            }
        }

        return components;
    }

    void Breadboard::addPin(Component& c, unsigned int pin_id, const ContactArea& area, unsigned int strip_pos) {
        /** to be used for setting pins into the power busses */

        if(strip_pos >= m_width) {
            std::cout << "Breadboard: cant set pin into " << strip_pos << " of the power bus, max position: " << m_width << "\n";
            return;
        }

        if(area == PowerBusPositive) {
            m_positive_power_bus.setConnection(&c,strip_pos, pin_id);
        } else if (area == PowerBusNegative) {
            m_negative_power_bus.setConnection(&c,strip_pos, pin_id);
        } else {
            std::cout << "BreadBoard: you have to specify a row and a half for pins being set into the main area" << "\n";
        }

    }

    void Breadboard::addPin(Component& c, unsigned int pin_id, const ContactArea& area, unsigned int strip_pos, unsigned int row, bool top_half) {
        /** to be used for setting pins into terminal strips */

        if(row > (m_terminal_strips.size() / 2)) {
            std::cout << "BreadBoard: failed to add pin into row " << row << ", max rows: " << m_terminal_strips.size() / 2 << "\n";
            return;
        }

        unsigned int contact_strip_id = top_half ? row : m_terminal_strips.size() / 2 + row;

        if(area == ContactStripArea) {
            m_terminal_strips.at(contact_strip_id).setConnection( &c, strip_pos, pin_id);
        }

    }

    undicht::Sprite& Breadboard::getSprite() {

        if(m_update_sprite) {
            updateSprite();
            m_update_sprite = false;
        }

        return m_sprite;
    }


    void Breadboard::updateSprite() {

        char* pixels;
        int  byte_size; // size of the texture
        BoardTexture::genColorTexture(pixels, *this, m_texture_width, m_texture_height, byte_size);

        undicht::core::BufferLayout pixel_layout({undicht::core::UND_VEC3F});

        m_sprite.setPixelFormat(pixel_layout);
        m_sprite.setSize(m_texture_width, m_texture_height);
        m_sprite.setData(pixels, byte_size);

        BoardTexture::freePixels(pixels);

        // unstretching the sprite
        if(m_width > m_height) {
            m_sprite.setScale(glm::vec2(1, float(m_height) / m_width));
        } else {
            m_sprite.setScale(glm::vec2(float(m_width) / m_height, 1));
        }

    }

    void Breadboard::setPower(float voltage) {
        /// negative power bus will be ground

        m_positive_power_bus.setVoltage(voltage, 0, 0);
        m_negative_power_bus.setVoltage(0, 0, 0);

    }


} // bread
