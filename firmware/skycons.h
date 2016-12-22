#ifndef PARTICLE_SKYCON_LIBRARY
#define PARTICLE_SKYCON_LIBRARY

#include "application.h"
#include "Adafruit_SSD1306.h"

#define SKYCON_PI                   3.14159265358979323846
#define SKYCON_TAU                  2.0 * SKYCON_PI
#define SKYCON_TWO_OVER_SQRT_2      2.0 / sqrt(2)

// #define SKYCON_WIND

class Skycons {
    private:
        Adafruit_SSD1306 *display;
        void circle(int x, int y, int r);
        void circle(int x, int y, int r, uint16_t color);
        void line(int ax, int ay, int bx, int by);
        void line(int ax, int ay, int bx, int by, uint16_t color);

#ifdef SKYCON_WIND
        int i_sin(int x);
        int i_cos(int x);
        void arc(float x, float y, float r, float start, float end, uint16_t color);
        void leaf(float t, float x, float y, float cw, uint16_t color);
        void lineTo(float x, float y);
        void moveTo(float x, float y);

        float to_x = 0;
        float to_y = 0;
#endif

        int stroke = 1;
        float sun_div = 24000;
        float moon_div = 24000;
        float cloud_div = 100000;
        float puff_size = 0.5; // Larger value = smaller cloud
        float cloud_puffs = 5;
        int sleet_multi = 4;
        int sleet_line = 3;
        int rain_multi = 5;
        float snow_div = 3000;
        float rain_div = 1350;
        float sleet_div = 1000;
        float snow_flakes = 3;
        float fog_div = 10000;
        float fog_line = 0.9;
        float wave_div = 2500;

        float last_cloud_t = 0;
        float last_rain_t = 0;
        float last_sleet_t = 0;
        float last_snow_t = 0;

#ifdef SKYCON_WIND
        uint8_t wind_counter = 0;
        int leaf_count = 2;
#endif

    public:
        Skycons(Adafruit_SSD1306 *display);
        Skycons(Adafruit_SSD1306 *display, int stroke);

        void setStroke(int s);
        void setRainDrops(int drops);
        void setSleetDrops(int drops);
        void setSnowFlakes(int flakes);

        void moon(float t, float x, float y, float d);
        void sun(float t, float x, float y, float d);
        void cloud(float t, float cx, float cy, float cw);
        void puff(float t, float cx, float cy, float rx, float ry, float rmin, float rmax, uint16_t color);
        void puffs(float t, float cx, float cy, float rx, float ry, float rmin, float rmax, uint16_t color);
        void puffs(float t, float cx, float cy, float rx, float ry, float rmin, float rmax);
        void rain(float t, float cx, float cy, float cw);
        void rain(float t, float cx, float cy, float cw, uint16_t color);
        void sleet(float t, float cx, float cy, float cw);
        void sleet(float t, float cx, float cy, float cw, uint16_t color);
        void snow(float t, float cx, float cy, float cw);
        void snow(float t, float cx, float cy, float cw, uint16_t color);

#ifdef SKYCON_WIND
        void wind(float t, float cx, float cy, float cw);
#endif
};
#endif