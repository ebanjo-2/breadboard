#include "renderer.h"
#include <2D/sprite_renderer.h>
#include <rendering/board_texture.h>

namespace bread {

    Renderer::Renderer() {
        //ctor
    }

    Renderer::~Renderer() {
        //dtor
    }

    undicht::Sprite* Renderer::getSprite(const Breadboard& board) {

        // checking if the objects sprite is already stored
        for(int i = 0; i < m_objects.size(); i++) {
            if(m_objects.at(i) == (void*)&board) {
                return &m_sprites.at(i);
            }
        }

        // or creating a new sprite
        char* pixels;
        int width, height, byte_size;
        BoardTexture::genColorTexture(pixels, board, width, height, byte_size);

        undicht::core::BufferLayout pixel_layout({undicht::core::UND_VEC3F});

        m_sprites.emplace_back(undicht::Sprite());
        m_sprites.back().setPixelFormat(pixel_layout);
        m_sprites.back().setSize(width, height);
        m_sprites.back().setData(pixels, byte_size);

        BoardTexture::freePixels(pixels);

        // unstretching the sprite
        if(board.m_width > board.m_height) {
            m_sprites.back().setScale(glm::vec2(1, float(board.m_height) / board.m_width));
        } else {
            m_sprites.back().setScale(glm::vec2(float(board.m_width) / board.m_height, 1));
        }

        m_objects.push_back((void*)&board);

        return &m_sprites.back();
    }


    void Renderer::draw(const Breadboard& board) {


        undicht::Sprite* board_sprite = getSprite(board);


        m_renderer.draw(*board_sprite);

    }

} // bread
