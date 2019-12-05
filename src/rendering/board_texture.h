#ifndef BOARD_TEXTURE_H
#define BOARD_TEXTURE_H

#include <breadboard.h>
#include <rendering/texture_generator.h>

namespace bread {

    class BoardTexture : public TextureGenerator{
        public:
            // a class that generates a board texture for a given Breadboard object

            static void genColorTexture(char*& rgb_color, const Breadboard& board, int& texture_width, int& texture_height, int& byte_size);

            static void addPin(char* texture, int pos_x, int pos_y, int texture_width, int pin_size, char* color);

            BoardTexture();
            virtual ~BoardTexture();

    };

} // bread

#endif // BOARD_TEXTURE_H
