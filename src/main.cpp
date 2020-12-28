#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const byte displayAddress = 0x27;

byte load0[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};
byte load1[8] = {0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000};
byte load2[8] = {0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000};
byte load3[8] = {0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100};
byte load4[8] = {0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110};
byte load5[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111};

int percent = 0;

LiquidCrystal_I2C lcd(displayAddress, 16, 2);

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.createChar(0, load0);
    lcd.createChar(1, load1);
    lcd.createChar(2, load2);
    lcd.createChar(3, load3);
    lcd.createChar(4, load4);
    lcd.createChar(5, load5);
}

void loop() {
    lcd.clear();

    for (int i = 0; i <= 16; i++) {
        for (int k = 0; k <= 5; k++) {
            lcd.setCursor(4, 0);
            lcd.print("Loading ");
            lcd.print(percent++);
            lcd.setCursor(i, 1);
            lcd.write(k);
            delay(250);

            if (percent > 100) {
                delay(1000);
                percent = 0;
                return;
            }
        }
    }
}