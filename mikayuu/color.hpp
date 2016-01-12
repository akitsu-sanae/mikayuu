#ifndef MIKAYUU_COLOR_HPP
#define MIKAYUU_COLOR_HPP

namespace mkyu {

struct Color {
    double r, g, b;
    static Color red() {
        return Color{1.0, 0.0, 0.0};
    }
    static Color green() {
        return Color{0.0, 1.0, 0.0};
    }
    static Color blue() {
        return Color{0.0, 0.0, 1.0};
    }
};

}

#endif
