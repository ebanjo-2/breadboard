#ifndef BREADBOARD_H
#define BREADBOARD_H

#include <component.h>
#include <contact_strip.h>

namespace bread {


    class Breadboard {
            /** holds and connects components
            * via contact points that are connected in strips */
        public:

            int m_width = 0;
            int m_height = 0;

            ContactStrip m_positive_power_bus;
            ContactStrip m_negative_power_bus;

            std::vector<ContactStrip> m_terminal_strips;

            enum ContactArea {

                PowerBusPositive,
                PowerBusNegative,
                ContactStripArea
            };

        public:

            /** @param width and height describing the number of contacts in the main area */
            void initialize(int width, int height);

            void getSize(int& width, int& height);

        public:

            /** to be used for setting pins into the power busses */
            void addPin(Component& c, unsigned int pin_id, const ContactArea& area, unsigned int strip_pos);

            /** to be used for setting pins into terminal strips */
            void addPin(Component& c, unsigned int pin_id, const ContactArea& area, unsigned int strip_pos, unsigned int row, bool top_half);

        public:

            /// negative power bus will be ground
            void setPower(float voltage);

            Breadboard();
            virtual ~Breadboard();

    };

} // bread

#endif // BREADBOARD_H
