#include "renderer.h"
#include <2D/sprite_renderer.h>
#include <rendering/board_texture.h>
#include <2D/physics/physics_math.h>

namespace bread {

    undicht::SpriteRenderer* Renderer::s_renderer = 0;


    Renderer::Renderer() {
        //ctor
    }

    Renderer::~Renderer() {
        //dtor
    }

    void Renderer::initialize() {

        s_renderer = new undicht::SpriteRenderer();

    }

    void Renderer::terminate() {

        delete s_renderer;
        s_renderer = 0;

    }


    void Renderer::draw(Breadboard& board) {

        s_renderer->draw(board.getSprite());

        std::vector<Component*> components = board.getComponents();
        std::cout << "drawing " << components.size() << " components " << "\n";
        for(Component* c : components) {
            draw(board, *c, &c->getSprite());
        }

    }


    void Renderer::draw(Breadboard& board, Component& component, undicht::Sprite* sprite) {
        /// draws the component

        // calculating the position of the first pin
        int pixel_pos_x, pixel_pos_y;
        BoardTexture::getPinPosition(board, component, 0, pixel_pos_x, pixel_pos_y);
        glm::vec2 position(float(pixel_pos_x) / board.m_texture_width, float(pixel_pos_y) / board.m_texture_height);
        position = position * 2.0f - 1.0f; // to (opengl screen) coordinates

        sprite->setPosition(glm::vec3(position, 0.0f));

        std::cout << "pixel position: " << pixel_pos_x << " " << pixel_pos_y << "\n";
        std::cout << "position: " << position.x << " " << position.y << "\n";
        std::cout << "board texture size: " << board.m_texture_width << " " << board.m_texture_height << "\n";

        s_renderer->draw(*sprite);

    }

} // bread
