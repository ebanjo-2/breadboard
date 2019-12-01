#ifndef CONTACT_STRIP_H
#define CONTACT_STRIP_H

#include <vector>


namespace bread {

    class Component;

    class ContactStrip {

        public:

            // components that have pins connected to the strip
            std::vector<Component*> m_components;

            // the pins of the components connected to the strip
            std::vector<unsigned int> m_pin_ids;

        public:

            void setSize(unsigned int number_of_contacts);

            /** the number of contact points in the strip */
            unsigned int getSize();

            void setConnection(Component* comp, unsigned int id, unsigned int pin_id);

            void setVoltage(float voltage, float resistance, Component* origin);


            ContactStrip();
            ContactStrip(unsigned int number_of_contacts);
            virtual ~ContactStrip();

    };

} // bread

#endif // CONTACT_STRIP_H
