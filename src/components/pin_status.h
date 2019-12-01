#ifndef PIN_STATUS_H
#define PIN_STATUS_H


#include <vector>


namespace bread {


    class PinStatus {
        public:

            static std::vector<PinStatus*> s_reset_list;

            static void addToResetList(PinStatus* pin);

            static void remFromResetList(PinStatus* pin);

            static void resetAllPins();

        public:

            float m_voltage = 0;
            float m_resistance = -1; // not connected to the voltage source

            // to be called on a new simulation cycle
            void reset();

            PinStatus();
            virtual ~PinStatus();

    };

} // bread

#endif // PIN_STATUS_H
