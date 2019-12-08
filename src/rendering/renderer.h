#ifndef BREAD_RENDERER_H
#define BREAD_RENDERER_H

#include <breadboard.h>
#include <2D/sprite.h>
#include <2D/sprite_renderer.h>

namespace bread {

    class Renderer {
        private:

            static undicht::SpriteRenderer* s_renderer;

            static undicht::Sprite* getSprite(const Breadboard& board);

            /// draws the component
            static void draw(Breadboard& board, Component& component, undicht::Sprite* sprite);

        public:

            static void initialize();
            static void terminate();

            static void draw(Breadboard& board);


            Renderer();
            virtual ~Renderer();

    };

} // bread

#endif // BREAD_RENDERER_H
