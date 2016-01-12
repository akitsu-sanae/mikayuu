#include <GLFW/glfw3.h>
#include <mikayuu/blend.hpp>

using namespace mkyu;

static BlendMode mode = BlendMode::None;

void mkyu::blend(BlendMode m) {
    mode = m;
    if (mode == mkyu::BlendMode::None)
        glDisable(GL_BLEND);
    else
        glEnable(GL_BLEND);
}

BlendMode mkyu::blend() {
    return mode;
}


void mkyu::detail::do_blend() {
    switch (mode) {
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

