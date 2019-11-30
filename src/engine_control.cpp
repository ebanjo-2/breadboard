#include "engine_control.h"

#include <core/core.h>


using namespace undicht;
using namespace undicht::core;
using namespace undicht::window;


namespace bread {

    // linux
    #ifdef UND_LINUX
        std::string window_lib = "engine/undicht/core/implementation/window/glfw/libwindow_glfw.so";
        std::string graphics_lib = "engine/undicht/core/implementation/graphics/opengl_33/libvideo_opengl_33.so";
        std::string audio_lib = "engine/undicht/core/implementation/audio/openal/libaudio_openal.so";
    #endif // UND_LINUX

    // windows
    #ifdef UND_WINDOWS
        std::string window_lib = "engine/undicht/core/implementation/window/glfw/window_glfw.dll";
        std::string graphics_lib = "engine/undicht/core/implementation/graphics/opengl_33/video_opengl_33.dll";
        std::string audio_lib = "engine/undicht/core/implementation/audio/openal/audio_openal.dll";
    #endif // UND_WINDOWS

    Window* window;
    GraphicsContext* context;
    KeyInputWatcher* key_input;

    void initializeEngine() {

        Core::setLibraryPaths(window_lib, graphics_lib, audio_lib);

        Engine::initialize(window, context);
        window->setSize(800, 600);

        key_input = new KeyInputWatcher;

        key_input->setWindow(window);

    }

    void terminateEngine() {

        delete key_input;

        Engine::terminate(window, context);

    }


} // bread
