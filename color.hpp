#pragma once

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color(int red = 0, int green = 0, int blue = 0, int alpha = 255)
        : r(colorClamp(red)), g(colorClamp(green)), b(colorClamp(blue)), a(colorClamp(alpha)) {}

    //Clamp para evitar valores invalidos
    unsigned char colorClamp(const int value) {
        if (value > 255) return 255;
        else if (value < 0) return 0;
        else return value;
    }

};

Color currentColor(255,255,255,255);
Color clearColor(0,0,0,255);

void setCurrentColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) {
	currentColor = Color(r, g, b, a);
}