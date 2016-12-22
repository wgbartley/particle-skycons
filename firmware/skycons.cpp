
#include "skycons.h"
#include "math.h"


#ifdef SKYCON_WIND
static float WIND_PATHS[2][128] = {{
    -0.7500, -0.1800, -0.7219, -0.1527, -0.6971, -0.1225,
    -0.6739, -0.0910, -0.6516, -0.0588, -0.6298, -0.0262,
    -0.6083,  0.0065, -0.5868,  0.0396, -0.5643,  0.0731,
    -0.5372,  0.1041, -0.5033,  0.1259, -0.4662,  0.1406,
    -0.4275,  0.1493, -0.3881,  0.1530, -0.3487,  0.1526,
    -0.3095,  0.1488, -0.2708,  0.1421, -0.2319,  0.1342,
    -0.1943,  0.1217, -0.1600,  0.1025, -0.1290,  0.0785,
    -0.1012,  0.0509, -0.0764,  0.0206, -0.0547, -0.0120,
    -0.0378, -0.0472, -0.0324, -0.0857, -0.0389, -0.1241,
    -0.0546, -0.1599, -0.0814, -0.1876, -0.1193, -0.1964,
    -0.1582, -0.1935, -0.1931, -0.1769, -0.2157, -0.1453,
    -0.2290, -0.1085, -0.2327, -0.0697, -0.2240, -0.0317,
    -0.2064,  0.0033, -0.1853,  0.0362, -0.1613,  0.0672,
    -0.1350,  0.0961, -0.1051,  0.1213, -0.0706,  0.1397,
    -0.0332,  0.1512,  0.0053,  0.1580,  0.0442,  0.1624,
    0.0833,  0.1636,  0.1224,  0.1615,  0.1613,  0.1565,
    0.1999,  0.1500,  0.2378,  0.1402,  0.2749,  0.1279,
    0.3118,  0.1147,  0.3487,  0.1015,  0.3858,  0.0892,
    0.4236,  0.0787,  0.4621,  0.0715,  0.5012,  0.0702,
    0.5398,  0.0766,  0.5768,  0.0890,  0.6123,  0.1055,
    0.6466,  0.1244,  0.6805,  0.1440,  0.7147,  0.1630,
    0.7500,  0.1800
}, {
    -0.7500,  0.0000, -0.7033,  0.0195, -0.6569,  0.0399,
    -0.6104,  0.0600, -0.5634,  0.0789, -0.5155,  0.0954,
    -0.4667,  0.1089, -0.4174,  0.1206, -0.3676,  0.1299,
    -0.3174,  0.1365, -0.2669,  0.1398, -0.2162,  0.1391,
    -0.1658,  0.1347, -0.1157,  0.1271, -0.0661,  0.1169,
    -0.0170,  0.1046,  0.0316,  0.0903,  0.0791,  0.0728,
    0.1259,  0.0534,  0.1723,  0.0331,  0.2188,  0.0129,
    0.2656, -0.0064,  0.3122, -0.0263,  0.3586, -0.0466,
    0.4052, -0.0665,  0.4525, -0.0847,  0.5007, -0.1002,
    0.5497, -0.1130,  0.5991, -0.1240,  0.6491, -0.1325,
    0.6994, -0.1380,  0.7500, -0.1400,
// The rest of this is actually copied from above to make a continuous path
                                        -0.2157, -0.1453,
    -0.2290, -0.1085, -0.2327, -0.0697, -0.2240, -0.0317,
    -0.2064,  0.0033, -0.1853,  0.0362, -0.1613,  0.0672,
    -0.1350,  0.0961, -0.1051,  0.1213, -0.0706,  0.1397,
    -0.0332,  0.1512,  0.0053,  0.1580,  0.0442,  0.1624,
    0.0833,  0.1636,  0.1224,  0.1615,  0.1613,  0.1565,
    0.1999,  0.1500,  0.2378,  0.1402,  0.2749,  0.1279,
    0.3118,  0.1147,  0.3487,  0.1015,  0.3858,  0.0892,
    0.4236,  0.0787,  0.4621,  0.0715,  0.5012,  0.0702,
    0.5398,  0.0766,  0.5768,  0.0890,  0.6123,  0.1055,
    0.6466,  0.1244,  0.6805,  0.1440,  0.7147,  0.1630,
    0.7500,  0.1800
}};


static const float WIND_OFFSETS[2][2] = {
    {0.36, 0.11},
    {0.56, 0.16}
};


static const uint8_t isinTable8[] = {
    0, 4, 9, 13, 18, 22, 27, 31, 35, 40, 44,
    49, 53, 57, 62, 66, 70, 75, 79, 83, 87,
    91, 96, 100, 104, 108, 112, 116, 120, 124, 128,
    131, 135, 139, 143, 146, 150, 153, 157, 160, 164,
    167, 171, 174, 177, 180, 183, 186, 190, 192, 195,
    198, 201, 204, 206, 209, 211, 214, 216, 219, 221,
    223, 225, 227, 229, 231, 233, 235, 236, 238, 240,
    241, 243, 244, 245, 246, 247, 248, 249, 250, 251,
    252, 253, 253, 254, 254, 254, 255, 255, 255, 255,
};
#endif


bool do_animation = true;


Skycons::Skycons(Adafruit_SSD1306 *display) {
    this->display = display;
    this->stroke = 1;
}


Skycons::Skycons(Adafruit_SSD1306 *display, int stroke) {
    this->display = display;
    this->stroke = stroke;
}


void Skycons::circle(int x, int y, int r) {
    this->circle(x, y, r, WHITE);
}


void Skycons::circle(int x, int y, int r, uint16_t color) {
    this->display->fillCircle(x, y, r, color);
}


void Skycons::line(int ax, int ay, int bx, int by) {
    this->line(ax, ay, bx, by, WHITE);
}


void Skycons::line(int ax, int ay, int bx, int by, uint16_t color) {
    this->display->drawLine(ax, ay, bx, by, color);
}


#ifdef SKYCON_WIND
int Skycons::i_sin(int x) {
    boolean pos = true;  // positive - keeps an eye on the sign.
    uint8_t idx;

    //remove next 6 lines for fastestl!
    /*     if (x < 0) {
    x = -x;
    pos = !pos;
    }
    if (x >= 360) x %= 360;   */

    if (x > 180) {
        idx = x - 180;
        pos = !pos;
    } else
        idx = x;

    if (idx > 90)
        idx = 180 - idx;
    if (pos)
        return isinTable8[idx]/2;

    return -(isinTable8[idx]/2);
}


int Skycons::i_cos(int x) {
    return i_sin(x+90);
}


void Skycons::arc(float x, float y, float r, float start, float end, uint16_t color) {
    int16_t l, i, w, x1, y1, x2, y2;
    unsigned short dw;

    if (end > start)
        dw = end-start;
    else
        dw = 256-start+end;

    if (dw == 0)
        dw = 256;
    //l = (uint8_t)(((((unsigned short)r * dw) >> 7) * (unsigned short)201)>>8);

    l = (uint8_t)(((((uint16_t)r * dw) >> 7) * (uint16_t)201)>>8);
    x1 = x+(((int16_t)r*(int16_t)this->i_cos(start)) >> 7);
    y1 = y+(((int16_t)r*(int16_t)this->i_sin(start)) >> 7);

    for (i = 1; i <= l; i++) {
        //w = ((unsigned short)dw*(unsigned short)i) / (unsigned short)l + rs;
        w = ((uint16_t)dw*(uint16_t)i) / (uint16_t)l + start;
        x2 = x+(((int16_t)r*(int16_t)this->i_cos(w)) >> 7);
        y2 = y+(((int16_t)r*(int16_t)this->i_sin(w)) >> 7);
        this->display->drawLine(x1,y1,x2,y2,color);
        x1 = x2;
        y1 = y2;
    }
}


void Skycons::lineTo(float x, float y) {
    line(this->to_x, this->to_y, x, y);

    this->to_x = x;
    this->to_y = y;
}


void Skycons::moveTo(float x, float y) {
    this->to_x = x;
    this->to_y = y;
}
#endif


void Skycons::setStroke(int s) {
    this->stroke = s;
}


void Skycons::setRainDrops(int drops) {
    this->rain_multi = drops;
}


void Skycons::setSleetDrops(int drops) {
    this->sleet_multi = drops;
}


void Skycons::setSnowFlakes(int flakes) {
    this->snow_flakes = flakes;
}


void Skycons::moon(float t, float x, float y, float r) {
    t /= moon_div;

    float a = (r*2) * 0.29 - this->stroke * 0.5,
          b = (r*2) * 0.05,
          c = cos(t*SKYCON_TAU),
          p = c * SKYCON_TAU / -16;

    this->circle(x, y, r);

    x += c*b-r/2;
    a *= 2;
    this->circle(x + cos(p) * a * SKYCON_TWO_OVER_SQRT_2, y + sin(p) * a * SKYCON_TWO_OVER_SQRT_2, a, BLACK);
}


void Skycons::sun(float t, float x, float y, float r) {
    t /= sun_div;

    float a = r*2 * 0.25 - this->stroke * 0.5,
          b = r*2 * 0.32 + this->stroke * 0.5,
          c = r*2 * 0.50 - this->stroke * 0.5,
          i, p, cosine, sine;

    // Clear the old sun
    this->circle(x, y, c+this->stroke*2, BLACK);

    this->circle(x, y, a);

    for(i=8; i--; ) {
        p = (t+i/8) * SKYCON_TAU;
        cosine = cos(p);
        sine = sin(p);

        this->line(
            x + cosine * b,
            y + sine * b,
            x + cosine * c,
            y + sine * c
        );
    }
}


void Skycons::cloud(float t, float cx, float cy, float cw) {
    t /= cloud_div;

    float a = cw * 0.21/puff_size,
          b = cw * 0.12/puff_size,
          c = cw * 0.24/puff_size,
          d = cw * 0.28/puff_size;

    // Clear out the old clouds
    if(this->last_cloud_t>0) {
        this->puffs(this->last_cloud_t, cx, cy, a, b, c, d, BLACK);
    }

    this->puffs(t, cx, cy, a, b, c, d, WHITE);
    this->puffs(t, cx, cy, a, b, c-this->stroke, d-this->stroke, BLACK);
    this->circle(cx, cy, cw/2.5, BLACK);

    this->last_cloud_t = t;
}


void Skycons::puff(float t, float cx, float cy, float rx, float ry, float rmin, float rmax, uint16_t color) {
    float c = cos(t*SKYCON_TAU)/puff_size,
          s = sin(t*SKYCON_TAU)/puff_size;

    rmax -= rmin;

    this->circle(
        cx - s * rx,
        cy + c * ry + rmax * 0.5,
        rmin + (1 - c * 0.5) * rmax,
        color
    );
}


void Skycons::puffs(float t, float cx, float cy, float rx, float ry, float rmin, float rmax, uint16_t color) {
    for(int i=cloud_puffs; i--; ) {
        this->puff(t+i/cloud_puffs, cx, cy, rx, ry, rmin, rmax, color);
    }
}


void Skycons::puffs(float t, float cx, float cy, float rx, float ry, float rmin, float rmax) {
    this->puffs(t, cx, cy, rx, ry, rmin, rmax, WHITE);
}


void Skycons::rain(float t, float cx, float cy, float cw) {
    if(this->last_rain_t>0)
        this->rain(last_rain_t, cx, cy, cw, BLACK);

    this->rain(t, cx, cy, cw, WHITE);

    this->last_rain_t = t;
}


void Skycons::rain(float t, float cx, float cy, float cw, uint16_t color) {
    t /= rain_div;

    float a = cw * 0.3,
          p, x, y;

    for(int i=this->rain_multi; i--; ) {
        p = fmod((t + i / this->rain_multi), 1) + 1;
        x = cx + ((i - 1.5) / 1.5) * ((i == 1 || i == 2) ? -1 : 1) * a;
        y = (cy + p * p * cw + i*this->rain_multi)-cw/4;

        this->circle(x, y, this->stroke, color);
    }
}


void Skycons::sleet(float t, float cx, float cy, float cw) {
    if(this->last_sleet_t>0)
        this->sleet(last_sleet_t, cx, cy, cw, BLACK);

    this->sleet(t, cx, cy, cw, WHITE);

    this->last_sleet_t = t;
}


void Skycons::sleet(float t, float cx, float cy, float cw, uint16_t color) {
    t /= sleet_div;

    float a = cw * 0.4,
          p, x, y;

    for(int i=this->sleet_multi; i--; ) {
        p = fmod((t + i / this->sleet_multi*10), 1);
        x = cx + ((i - 1.5) / 1.5) * ((i == 1 || i == 2) ? -1 : 1) * a;
        y = (cy + p * p * cw + i*this->sleet_multi*2)-cw/4;

        line(x, y-this->stroke * this->sleet_line, x, y+this->stroke * this->sleet_line, color); // length
    }
}


void Skycons::snow(float t, float cx, float cy, float cw) {
    if(this->last_snow_t>=0)
        this->snow(this->last_snow_t, cx, cy, cw, BLACK);

    this->snow(t, cx, cy, cw, WHITE);

    this->last_snow_t = t;
}


void Skycons::snow(float t, float cx, float cy, float cw, uint16_t color) {
    t /= this->snow_div;

    float a = cw * 0.16,
          b = this->stroke * 0.75,
          u = t * SKYCON_TAU * 0.7,
          ux = cos(u) * b,
          uy = sin(u) * b,
          v = u + SKYCON_TAU / 3,
          vx = cos(v) * b,
          vy = sin(v) * b,
          w = u + SKYCON_TAU * 2 / 3,
          wx = cos(w) * b,
          wy = sin(w) * b,
          p, x, y;

    for(float i=this->snow_flakes; i--; ) {
        p = fmod((t + i / this->snow_flakes), 1);
        x = cx + sin((p + i / this->snow_flakes) * SKYCON_TAU) *a;
        y = cy + p * cw + (i*this->snow_flakes);

        this->line(x-ux, y-uy, x+ux, y+uy, color);
        this->line(x-vx, y-vy, x+vx, y+vy, color);
        this->line(x-wx, y-wy, x+wx, y+wy, color);
    }
}


#ifdef SKYCON_WIND
void Skycons::leaf(float t, float x, float y, float cw, uint16_t color) {
    float a = cw / 8,
          b = a / 3,
          c = 2 * b,
          d = fmod(t, 1) * SKYCON_TAU,
          e = cos(d),
          f = sin(d);

    // arc(x, y, a, d, d+PI); // Makes no difference?
    // circle(x, y, a, WHITE);
    this->arc(x - b * e, y - b * f, c, d + SKYCON_PI, d, color); // leaf body
    // circle(x-b * e, y - b * f, c, BLACK);
    this->arc(x + c * e, y + c * f, b, d + SKYCON_PI, d, color);
}


void Skycons::wind(float t, float cx, float cy, float cw) {
    t /= wave_div;

    int index = this->wind_counter;
    this->wind_counter++;

    if(this->wind_counter==255)
        this->wind_counter = 0;

    int total = this->leaf_count;

    int path_size = (sizeof(WIND_PATHS[index])/sizeof(float));

    float a = fmod(t + index - WIND_OFFSETS[index][0], total),
          c = fmod(t + index - WIND_OFFSETS[index][1], total),
          e = fmod(t + index, total),
          b, d, f, i;

    if(a<1) {
        a *= path_size / 2 -1;
        b  = (int)a;
        a -= b;
        b *= 2;
        b += 2;

        this->moveTo(
            cx + (WIND_PATHS[index][(int)b - 2] * (1 - a) + WIND_PATHS[index][(int)b] * a) * cw,
            cy + (WIND_PATHS[index][(int)b - 1] * (1 - a) + WIND_PATHS[index][(int)b+1] * a) * cw
        );

        if(c<1) {
            c *= path_size / 2 - 1;
            d  = (int)c;
            c -= d;
            d *= 2;
            d += 2;

            // This causes an SOS
            for(i=b; i!=d; i +=2) {
                this->lineTo(
                    cx + WIND_PATHS[index][(int)i] * cw,
                    cy + WIND_PATHS[index][(int)i+1] * cw
                );
            }

            this->lineTo(
                cx + (WIND_PATHS[index][(int)d-2] * (1-c) + WIND_PATHS[index][(int)d] * c) * cw,
                cy + (WIND_PATHS[index][(int)d-1] * (1-c) + WIND_PATHS[index][(int)d+1] * c) *cw
            );
        } else {
            for(i=b; i!=path_size; i+=2) {
                this->lineTo(
                    cx + WIND_PATHS[index][(int)i] * cw,
                    cy + WIND_PATHS[index][(int)i + 1] *cw
                );
            }
        }
    } else if(c<1) {
        c *= path_size / 2 - 1;
        d  = (int)c;
        c -= d;
        d *= 2;
        d += 2;

        this->moveTo(
            cx + WIND_PATHS[index][0] * cw,
            cy + WIND_PATHS[index][1] * cw
        );

        for(i=2; i!=d; i+=2) {
            this->lineTo(
                cx + WIND_PATHS[index][(int)i] * cw,
                cy + WIND_PATHS[index][(int)i + 1] * cw
            );
        }

        this->lineTo(
            cx + (WIND_PATHS[index][(int)d - 2] * (1 - c) + WIND_PATHS[index][(int)d    ] * c) * cw,
            cy + (WIND_PATHS[index][(int)d - 1] * (1 - c) + WIND_PATHS[index][(int)d + 1] * c) * cw
        );
    }


    if(e<1) {
        e *= path_size / 2 - 1;
        f  = (int)e;
        e -= f;
        f *= 2;
        f += 2;

        this->leaf(
            t,
            cx + (WIND_PATHS[index][(int)f-2] * (1-e) + WIND_PATHS[index][(int)f]*e) * cw,
            cy + (WIND_PATHS[index][(int)f-1] * (1-e) + WIND_PATHS[index][(int)f+1]*e) * cw,
            cw,
            WHITE
        );
    }
}
#endif