#include "component.h"
#include <iostream>
#include <contact_strip.h>

namespace bread {

    Component::Component() {
        //ctor
    }

    Component::~Component() {
        //dtor

    }


    void Component::setVoltage(unsigned int pin_id, float voltage, float resistance) {
        /** called when there is a voltage applied to the components pin
        * to be implemented by derived classes */
    }


    void Component::setPinCount(unsigned int num) {

        m_contacts.resize(num);

    }

    void Component::setConnection(ContactStrip* contact, int pin_id) {

        if((pin_id >= 0) && (m_contacts.size() > pin_id)) {

            m_contacts.at(pin_id) = contact;

        } else {

            std::cout << "cant connect pin " << pin_id << ", component has " << m_contacts.size() << " contact pins" << "\n";

        }


    }


    void Component::outputVoltage(unsigned int pin_id, float voltage, float resistance) {

        if((pin_id < m_contacts.size()) && (pin_id >= 0)) {

            m_contacts.at(pin_id)->setVoltage(voltage, resistance, this);

        } else {

            std::cout << "failed to output voltage to pin " << pin_id << "\n";

        }

    }


} // bread
