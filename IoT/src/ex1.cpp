#include "Arduino.h"

#define RED_LED_PIN     26
#define GREEN_LED_PIN   27
#define YELLOW_LED_PIN  12
#define BLUE_LED_PIN    14

// LED chase ketma-ketligi
const int ledPins[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN,
    YELLOW_LED_PIN,
    GREEN_LED_PIN
};

// LED nomlari
const char* ledNames[] = {
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "YELLOW",
    "GREEN"
};

const int ledCount = 6;

// Ketma-ketlikdagi joriy qadam
int stepIndex = 0;


/****************************************************/
void setup(void)
{
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    Serial.begin(115200);

    // Boshlanishida barcha LEDlarni o'chirish
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}


/****************************************************/
void loop(void)
{
    // Barcha LEDlarni o'chirish
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);

    // Joriy LEDni yoqish
    digitalWrite(ledPins[stepIndex], HIGH);

    // Serial Monitor'ga LED nomini chiqarish
    Serial.print("chase=");
    Serial.println(ledNames[stepIndex]);

    // Bitta qadam uchun 150 ms kutish
    delay(150);

    // Keyingi qadamga o'tish
    stepIndex++;

    // Oxirgi qadamdan keyin yana boshidan boshlash
    if (stepIndex >= ledCount)
    {
        stepIndex = 0;
    }
}