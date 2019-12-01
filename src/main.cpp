#include <engine_control.h>
#include <breadboard.h>
#include <components/led.h>

using namespace bread;

int main() {

    initializeEngine();

    {

        Breadboard board;
        board.initialize(50, 10);

        LED red_led(1,0,0);
        LED green_led(0,1,0);
        LED blue_led(0,0,1);

        // connecting the red led
        board.addPin(red_led, 0, Breadboard::PowerBusPositive, 0);
        board.addPin(red_led, 1, Breadboard::ContactStripArea, 0, 0, true);

        // connecting the green led
        board.addPin(green_led, 0, Breadboard::ContactStripArea, 1, 0, true);
        board.addPin(green_led, 1, Breadboard::ContactStripArea, 0, 1, true);

        // connecting the blue led
        board.addPin(blue_led, 0, Breadboard::ContactStripArea, 1, 1, true);
        board.addPin(blue_led, 1, Breadboard::PowerBusNegative, 0);

        board.setPower(2.3);

        red_led.getStatus();
        green_led.getStatus();
        blue_led.getStatus();

        while(!window->shouldClose()) {

            window->update();

        }


    }

    terminateEngine();

    return 0;
}
