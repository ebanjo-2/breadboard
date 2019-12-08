#include "board_texture.h"
#include <iostream>

namespace bread {

    // sizes in pixels
    const int PIN_SIZE = 2;
    const int PIN_GAP = 2; // gap between pins
    const int BORDER = 1; // border on each side of the board
    const int MID = 2; // width of the gap in the mid

    // color of pins in different areas
    const glm::vec3 PIN_COLOR(0.0f,0.0f,0.0f); // default pin color
    const glm::vec3 POS_COLOR(1.0f,0.0f,0.0f); // positive power bus color
    const glm::vec3 NEG_COLOR(0.0f,0.0f,1.0f); // negative power bus color

    // color of the board
    const glm::vec3 BOARD_COLOR(0.8f,0.8f,0.8f);

    BoardTexture::BoardTexture() {
        //ctor
    }

    BoardTexture::~BoardTexture() {
        //dtor
    }


    void BoardTexture::genColorTexture(char*& rgb_color, const Breadboard& board, int& texture_width, int& texture_height, int& byte_size) {

        texture_width = (board.m_width + 2) * (PIN_SIZE + PIN_GAP) + BORDER * 2 + MID;
        texture_height = board.m_height * (PIN_SIZE + PIN_GAP);

        rgb_color = genTexture(texture_width, texture_height, BOARD_COLOR);

        byte_size = texture_width * texture_height * 3;

        int x_offset;
        int y_offset = BORDER;

        int pos_x, pos_y;

        // adding the pins
        for(int y = 0; y < board.m_height; y++) {

            for(int x = 0; x < board.m_width + 2; x++) { // + 2 for power busses

                if(x >= (board.m_width + 2) / 2) {
                    // mid
                    x_offset = BORDER + MID;
                } else {
                    // making a border on the left
                    x_offset = BORDER;
                }

                pos_x = x * (PIN_SIZE  + PIN_GAP) + x_offset;
                pos_y = y * (PIN_SIZE  + PIN_GAP) + y_offset;

                if(x == 0) {
                    // positive power bus
                    addPin(rgb_color, pos_x, pos_y, texture_width, PIN_SIZE, to24BitColor(POS_COLOR));
                } else if (x == board.m_width + 1) {
                    // negative power bus
                    addPin(rgb_color, pos_x, pos_y, texture_width, PIN_SIZE, to24BitColor(NEG_COLOR));
                } else {
                    // terminal strip area
                    addPin(rgb_color, pos_x, pos_y, texture_width, PIN_SIZE, to24BitColor(PIN_COLOR));
                }

            }

        }

    }


    void BoardTexture::addPin(char* texture, int pos_x, int pos_y, int texture_width, int pin_size, char* color) {

        for(int y = 0; y < pin_size; y++) {

            for(int x = 0; x < pin_size; x++) {

                texture[((pos_y + y) * texture_width + (pos_x + x)) * 3 + 0] = color[0];
                texture[((pos_y + y) * texture_width + (pos_x + x)) * 3 + 1] = color[1];
                texture[((pos_y + y) * texture_width + (pos_x + x)) * 3 + 2] = color[2];

            }

        }


    }

    void BoardTexture::getPinPosition(const Breadboard& board, const Component& component, int pin_id, int& pos_x, int& pos_y) {
        /** stores the position of the components pin on the board texture in the position parameters */

        // getting information about the contact
        ContactStrip* contact = component.m_contacts.at(pin_id);
        bool pos_power_bus = (contact == &board.m_positive_power_bus); // whether the contact is on the positive power bus
        bool neg_power_bus = (contact == &board.m_negative_power_bus); // whether the contact is on the negative power bus
        int strip_position = 0; // the position of the pin on the contact strip
        int strip_id = 0; // the id of the contact strip in the terminal area

        for(int i = 0; i < contact->getSize(); i++) {
            if(contact->m_components.at(i) == &component) {
                strip_position = i; // found the component on the contact
                break;
            }
        }

        // calculating the id of the contact strip in the terminal area
        if((!pos_power_bus) && (!neg_power_bus)) {
            for(int i = 0; i < board.m_height * 2; i++) {
                if(&board.m_terminal_strips.at(i) == contact) {
                    strip_id = i; // found the contact strip on the boards terminal area
                    break;
                }
            }
        }

        // calculating the position on the board texture
        if(pos_power_bus) {
            // on the left
            pos_x = BORDER;
            pos_y = BORDER + strip_position * (PIN_SIZE + PIN_GAP);
        } else if (neg_power_bus) {
            pos_x = BORDER + board.m_width * (PIN_SIZE + PIN_GAP);
            pos_y = BORDER + strip_position * (PIN_SIZE + PIN_GAP);
        } else {
            // terminal area
            bool right_half = (strip_id >= (board.m_width / 2));
            pos_x = BORDER + (right_half * (board.m_width / 2) + right_half * MID + strip_position) * (PIN_SIZE + PIN_GAP);
            pos_y = BORDER + strip_id * (PIN_SIZE + PIN_GAP);
        }

    }



} // bread
