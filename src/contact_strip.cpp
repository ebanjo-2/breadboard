#include "contact_strip.h"
#include <component.h>
#include <iostream>

namespace bread {

    ContactStrip::ContactStrip() {
        //ctor
    }

    ContactStrip::ContactStrip(unsigned int number_of_contacts) {

        setSize(number_of_contacts);
    }

    ContactStrip::~ContactStrip() {
        //dtor
    }


    void ContactStrip::setSize(unsigned int number_of_contacts) {

        m_components.resize(number_of_contacts, 0);
        m_pin_ids.resize(number_of_contacts, 0);
    }

    unsigned int ContactStrip::getSize() {

        return m_components.size();
    }

    void ContactStrip::setConnection(Component* comp, unsigned int id, unsigned int pin_id) {

        m_components.at(id) = comp;
        m_pin_ids.at(id) = pin_id;

        comp->setConnection(this, pin_id);

    }


    void ContactStrip::setVoltage(float voltage, float resistance, Component* origin) {
        // distributing the voltage

        for(int i = 0; i < m_components.size(); i++) {

            if((m_components.at(i) != origin) && (m_components.at(i) != nullptr)) {

                m_components.at(i)->setVoltage(m_pin_ids.at(i), voltage, resistance);

            }

        }

    }


} // bread
