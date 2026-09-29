#include "Arduino.h"

#define LIGHT_PIN 33

/****************************************************/
void setup(void)
{
    Serial.begin(115200);

    pinMode(LIGHT_PIN, INPUT);
}


/****************************************************/
void loop(void)
{
    int minValue = 4095;
    int maxValue = 0;
    long sum = 0;

    // 10 ta ketma-ket sensor namunasi
    for (int i = 0; i < 10; i++)
    {
        int value = analogRead(LIGHT_PIN);

        if (value < minValue)
        {
            minValue = value;
        }

        if (value > maxValue)
        {
            maxValue = value;
        }

        sum += value;
    }

    // O'rtacha qiymat
    int average = sum / 10;

    // Serial natija
    Serial.print("min=");
    Serial.print(minValue);

    Serial.print(" max=");
    Serial.print(maxValue);

    Serial.print(" avg=");
    Serial.println(average);

    // Har 1000 ms da yangi 10 ta sample
    delay(1000);
}