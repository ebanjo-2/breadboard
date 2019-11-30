#include <engine_control.h>

using namespace bread;

int main() {

    initializeEngine();

    {


        while(!window->shouldClose()) {

            window->update();

        }


    }

    terminateEngine();

    return 0;
}
