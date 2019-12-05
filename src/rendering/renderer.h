#ifndef BREAD_RENDERER_H
#define BREAD_RENDERER_H

#include <breadboard.h>
#include <2D/sprite.h>
#include <2D/sprite_renderer.h>

namespace bread {

    class Renderer {
        private:

            std::vector<undicht::Sprite> m_sprites;
            std::vector<void*> m_objects; // the objects for which the sprites are stored

            undicht::SpriteRenderer m_renderer;

            undicht::Sprite* getSprite(const Breadboard& board);

        public:

            void draw(const Breadboard& board);


            Renderer();
            virtual ~Renderer();

    };

} // bread

#endif // BREAD_RENDERER_H
