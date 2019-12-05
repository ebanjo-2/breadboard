#include "texture_generator.h"
#include <algorithm>
#include <iostream>

namespace bread {

    TextureGenerator::TextureGenerator() {
        //ctor
    }

    TextureGenerator::~TextureGenerator() {
        //dtor
    }


    void TextureGenerator::freePixels(char* pixels) {
        /** to be called with any pointer holding a generated texture
        * basically all this does is delete[] pixels; */
        delete[] pixels;
    }

    char* TextureGenerator::genTexture(int width, int height, const glm::vec3& color) {
        /** @return an array of chars the size of width * height * 3
        * filled with the color converted into 24 Bit color */

        char* pixels = new char[width * height * 3];
        char* byte_color = to24BitColor(color);


        for(int i = 0; i < width * height ; i++) {
            // std::cout << i << "  " << width * height << "\n";
            std::copy(byte_color, byte_color + 3, pixels + i * 3);
        }

        freePixels(byte_color);

        return pixels;
    }

    char* TextureGenerator::to24BitColor(const glm::vec3& color) {
        /** converts the color format used by texture generators into a 24 Bit rgb color */

        char* bit_color = new char[3];
        bit_color[0] = (char)(color.x * 255);
        bit_color[1] = (char)(color.y * 255);
        bit_color[2] = (char)(color.z * 255);

        return bit_color;
    }

} // bread
