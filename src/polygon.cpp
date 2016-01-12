#include <GLFw/glfw3.h>
#include <mikayuu/polygon.hpp>

namespace mkyu {

template<int N>
void Polygon<N>::draw() const {
    glColor3d(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (auto&& e : position)
        glVertex2d(e.x, e.y);
    glEnd();
}

template<>
void Polygon<3>::draw() const {
    glColor3d(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    for (auto&& e : position)
        glVertex2d(e.x ,e.y);
    glEnd();
}

template<>
void Polygon<4>::draw() const {
    glColor3d(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    for (auto&& e : position)
        glVertex2d(e.x, e.y);
    glEnd();
}

}
