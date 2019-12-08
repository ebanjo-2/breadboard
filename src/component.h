#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <2D/sprite.h>


namespace bread {

    class ContactStrip;


    class Component {
            /** the base class to all components that can be put on a breadboard*/
        public:

            std::vector<ContactStrip*> m_contacts; // the contact strips the components pins are connected to

            Component();
            virtual ~Component();

            /** called when there is a voltage applied to the components pin
            * to be implemented by derived classes */
            virtual void setVoltage(unsigned int pin_id, float voltage, float resistance);

            virtual void setPinCount(unsigned int num);

            virtual void setConnection(ContactStrip* contact, int pin_id);

        public:
            // functions to draw the component

            virtual undicht::Sprite& getSprite();

        protected:

            virtual void outputVoltage(unsigned int pin_id, float voltage, float resistance);

    };

} // bread

#endif // COMPONENT_H
