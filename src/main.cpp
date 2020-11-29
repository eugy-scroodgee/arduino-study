#include <Arduino.h>

const int redPort = 12;
const int yellowPort = 11;
const int greenPort = 10;

const int garlandLength = 6;
const int colorsNumber = 4;

const int ports[garlandLength] {11, 10, 9, 6, 5, 3};

void setup() {
    for (int port : ports) {
        pinMode(port, OUTPUT);
    }
}

void applySimpleToPin(int pin) {
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
}

void simpleMode() {
    for (int port : ports) {
        applySimpleToPin(port);
    }
}

void applyFadeToPin(int pin) {
    for (int i = 0; i < 255; i++) {
        analogWrite(pin, i);
        delay(5);
    }
    digitalWrite(pin, HIGH);

    for (int i = 255; i > 0; i--) {
        analogWrite(pin, i);
        delay(5);
    }

    digitalWrite(pin, LOW);
}

void fadeMode() {
    for (int port : ports) {
        applyFadeToPin(port);
    }
}

void applyFastToPin(int pin) {
    for (int i = 0; i < 255; i++) {
        analogWrite(pin, i);
        delay(1);
    }
    digitalWrite(pin, HIGH);

    for (int i = 255; i > 0; i--) {
        analogWrite(pin, i);
        delay(1);
    }

    digitalWrite(pin, LOW);
}

void fastMode() {
    for (int port : ports) {
        applyFastToPin(port);
    }

    for (int port : ports) {
        applyFastToPin(port);
    }

    for (int port : ports) {
        applyFastToPin(port);
    }
}

void allFadeMode() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 255; j++) {
            for (int port : ports) {
                analogWrite(port, j);
            }
            delay(5);
        }

        for (int j = 255; j > 0; j--) {
            for (int port : ports) {
                analogWrite(port, j);
            }
            delay(5);
        }
    }
}

void loop() {
    simpleMode();
    fadeMode();
    allFadeMode();
    fastMode();
}