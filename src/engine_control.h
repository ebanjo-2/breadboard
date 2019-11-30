#ifndef ENGINE_CONTROL_H
#define ENGINE_CONTROL_H

#include <engine.h>
#include <window/graphics_context.h>
#include <window/key_input_watcher.h>

namespace bread {

    extern undicht::window::Window* window;
    extern undicht::window::GraphicsContext* context;
    extern undicht::window::KeyInputWatcher* key_input;

    void initializeEngine();

    void terminateEngine();

} // bread

#endif // ENGINE_CONTROL_H
