#ifndef TEXTURE_GENERATOR_H
#define TEXTURE_GENERATOR_H

#include <glm/glm/glm.hpp>


namespace bread {


    class TextureGenerator {
        /** a base class with functions for texture generating classes */
        public:

            /** to be called with any pointer holding a generated texture
            * basically all this does is delete[] pixels; */
            static void freePixels(char* pixels);

            /** @return an array of chars the size of width * height * 3
            * filled with the color converted into 24 Bit color */
            static char* genTexture(int width, int height, const glm::vec3& color);

            /** converts the color format used by texture generators into a 24 Bit rgb color */
            static char* to24BitColor(const glm::vec3& color);

            TextureGenerator();
            virtual ~TextureGenerator();

    };

} // bread

#endif // TEXTURE_GENERATOR_H
