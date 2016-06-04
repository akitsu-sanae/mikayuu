#include <GLFW/glfw3.h>
#include <mikayuu/polygon.hpp>

namespace mkyu {

template<int N>
void Polygon<N>::draw() const {
    do_blend();
    glColor4d(color.r/255.0, color.g/255.0, color.b/255.0, color.a/255.0);
    glBegin(GL_POLYGON);
    for (auto&& e : position)
        glVertex2d(e.x, e.y);
    glEnd();
}

template<>
void Polygon<3>::draw() const {
    do_blend();
    glColor4d(color.r/255.0, color.g/255.0, color.b/255.0, color.a/255.0);
    glBegin(GL_TRIANGLES);
    for (auto&& e : position)
        glVertex2d(e.x ,e.y);
    glEnd();
}

template<>
void Polygon<4>::draw() const {
    do_blend();
    glColor4d(color.r/255.0, color.g/255.0, color.b/255.0, color.a/255.0);
    glBegin(GL_QUADS);
    for (auto&& e : position)
        glVertex2d(e.x, e.y);
    glEnd();
}

template<int N>
void Polygon<N>::do_blend() const {
    if (blend_mode == BlendMode::None) {
        glDisable(GL_BLEND);
        return;
    }

    glEnable(GL_BLEND);

    switch (blend_mode) {
    case BlendMode::None:
        break;
    case BlendMode::Alpha:
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        break;
    case BlendMode::Reverse:
        glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
        break;
    case BlendMode::Add:
        glBlendFunc(GL_ONE, GL_ONE);
        break;
    case BlendMode::Screen:
        glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
        break;
    case BlendMode::Mult:
        glBlendFunc(GL_ZERO, GL_SRC_COLOR);
        break;
    }
}


}
