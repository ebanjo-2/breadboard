#include "board_texture.h"
#include <iostream>

namespace bread {

    BoardTexture::BoardTexture() {
        //ctor
    }

    BoardTexture::~BoardTexture() {
        //dtor
    }


    void BoardTexture::genColorTexture(char*& rgb_color, const Breadboard& board, int& texture_width, int& texture_height, int& byte_size) {

        texture_width = (board.m_width + 2) * 5 + 2;
        texture_height = board.m_height * 5;

        rgb_color = genTexture(texture_width, texture_height, glm::vec3(0.8f,0.8f,0.8f));

        byte_size = texture_width * texture_height * 3;

        int offset;

        // adding the pins
        for(int y = 0; y < board.m_height; y++) {

            for(int x = 0; x < board.m_width + 2; x++) {

                if(x == (board.m_width + 2) / 2) {
                    // mid
                    offset = 6;
                } else {
                    // making a border on the left
                    offset = 2;
                }

                if(x == 0) {
                    // positive power bus: should be red
                    addPin(rgb_color, x * 5 + offset, y * 5 + 2, texture_width, 2, to24BitColor(glm::vec3(1,0,0)));
                } else if (x == board.m_width + 1) {
                    // negative power bus: should be blue
                    addPin(rgb_color, x * 5 + offset, y * 5 + 2, texture_width, 2, to24BitColor(glm::vec3(0,0,1)));
                } else {
                    // terminal strip area: should be black
                    addPin(rgb_color, x * 5 + offset, y * 5 + 2, texture_width, 2, to24BitColor(glm::vec3(0,0,0)));
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



} // bread
