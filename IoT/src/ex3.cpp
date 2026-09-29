#include "Arduino.h"

#define LIGHT_PIN 33

bool alertActive = false;


/****************************************************/
void setup(void)
{
    Serial.begin(115200);

    pinMode(LIGHT_PIN, INPUT);
}


/****************************************************/
void loop(void)
{
    // LIGHT sensor qiymatini o'qish
    int lightValue = analogRead(LIGHT_PIN);

    // Alertni yoqish
    if (lightValue > 3000 && !alertActive)
    {
        alertActive = true;
        Serial.println("ALERT=1");
    }

    // Alertni o'chirish
    if (lightValue < 2500 && alertActive)
    {
        alertActive = false;
        Serial.println("ALERT=0");
    }

    // Har 300 ms da tekshirish
    delay(300);
}