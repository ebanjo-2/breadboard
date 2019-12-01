#include "pin_status.h"

namespace bread {

    std::vector<PinStatus*> PinStatus::s_reset_list;

    void PinStatus::addToResetList(PinStatus* pin) {

        s_reset_list.push_back(pin);

    }

    void PinStatus::remFromResetList(PinStatus* pin) {

        for(int i = 0; i < s_reset_list.size(); i++) {

            if(pin == s_reset_list.at(i)) {
                s_reset_list.erase(s_reset_list.begin() + i);
                return;
            }

        }

    }

    void PinStatus::resetAllPins() {

        for(PinStatus*& pin : s_reset_list) {
            pin->reset();
        }
    }


    PinStatus::PinStatus() {

        addToResetList(this);
    }

    PinStatus::~PinStatus() {

        remFromResetList(this);
    }

    void PinStatus::reset() {

        m_voltage = 0;
        m_resistance = -1;

    }

} // bread
