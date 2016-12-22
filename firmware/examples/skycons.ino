#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
Adafruit_SSD1306 display(D0);

#include "skycons/skycons.h"
Skycons skycon(&display, 1);


void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.clearDisplay();
    display.display();
}


void loop() {
    int now_millis = millis();

    int t = now_millis/1000/10;

    switch(t) {
        case 1: // Moon
            skycon.moon(now_millis, 28, 38, 16);
            break;

        case 2: // Cloudy
            skycon.cloud(now_millis, 28, 38, 16);
            break;

        case 3: // Partly sunny
            skycon.sun(now_millis, 32, 30, 12);
            skycon.cloud(now_millis, 24, 42, 12);
            break;

        case 4: // Partly cloudy night
            skycon.moon(now_millis, 34, 30, 8);
            skycon.cloud(now_millis, 24, 42, 12);
            break;

        case 5: // Rain
            skycon.rain(now_millis, 28, 38, 16);
            skycon.cloud(now_millis, 28, 38, 16);
            break;

        case 6: // Sleet
            skycon.sleet(now_millis, 28, 38, 16);
            skycon.cloud(now_millis, 28, 38, 16);
            break;

        case 7: // Snow
            skycon.snow(now_millis, 28, 38, 16);
            skycon.cloud(now_millis, 28, 38, 16);
            break;

        defaut: // Sunny
            skycon.sun(now_millis, 28, 38, 16);
    }


    display.display();
    delay(1);
}