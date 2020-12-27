#include <Arduino.h>

using namespace std;

const int katode1 = 11;
const int katode2 = 12;


const int pinLedStart = 2;
const int pinLedSEnd = 8;

const int pinPot = A0;

byte numberToLedMap[10] = {
        0b00111111,
        0b00000110,
        0b01011011,
        0b01001111,
        0b01100110,
        0b01101101,
        0b01111101,
        0b00000111,
        0b01111111,
        0b01101111,
};

void setup() {
    Serial.begin(9600);

    for (int i = pinLedStart; i <= pinLedSEnd; i++) {
        pinMode(i, OUTPUT);
    }

    pinMode(katode1, OUTPUT);
    pinMode(katode2, OUTPUT);
}

void loop() {
    int number = analogRead(pinPot);

    Serial.println(number);

    number = map(number, 0, 1020, 0, 9);

    Serial.println(number);

    int mask = numberToLedMap[number];

    digitalWrite(katode1, HIGH);
    digitalWrite(katode2, LOW);

    for (int i = 0; i <= (pinLedSEnd - pinLedStart); i++) {
        digitalWrite(pinLedStart + i, bitRead(mask, i));
    }

    delay(5);

    digitalWrite(katode1, LOW);
    digitalWrite(katode2, HIGH);

    for (int i = 0; i <= (pinLedSEnd - pinLedStart); i++) {
        digitalWrite(pinLedStart + i, bitRead(mask, i));
    }

    delay(5);
}