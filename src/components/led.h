#ifndef LED_H
#define LED_H

#include <component.h>
#include <components/pin_status.h>


namespace bread {


    class LED : public Component {
        public:

            PinStatus m_p_pin; // 0
            PinStatus m_n_pin; // 1

            float m_r = 0, m_g = 0, m_b = 0;

            virtual void setVoltage(unsigned int pin_id, float voltage, float resistance);

            /** @return 1 if the led is shining, 0 if not */
            int getStatus();

            LED();
            LED(float r, float g, float b);
            virtual ~LED();

    };

} // bread

#endif // LED_H
