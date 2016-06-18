/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <array>
#include <GLFW/glfw3.h>
#include <mikayuu/keyboard.hpp>

namespace mkyu {

static Keyboard::Type convert_key(int key) {
    switch(key) {
    case GLFW_KEY_A:
        return Keyboard::Type::A;
    case GLFW_KEY_B:
        return Keyboard::Type::B;
    case GLFW_KEY_C:
        return Keyboard::Type::C;
    case GLFW_KEY_D:
        return Keyboard::Type::D;
    case GLFW_KEY_E:
        return Keyboard::Type::E;
    case GLFW_KEY_F:
        return Keyboard::Type::F;
    case GLFW_KEY_G:
        return Keyboard::Type::G;
    case GLFW_KEY_H:
        return Keyboard::Type::H;
    case GLFW_KEY_I:
        return Keyboard::Type::I;
    case GLFW_KEY_J:
        return Keyboard::Type::J;
    case GLFW_KEY_K:
        return Keyboard::Type::K;
    case GLFW_KEY_L:
        return Keyboard::Type::L;
    case GLFW_KEY_M:
        return Keyboard::Type::M;
    case GLFW_KEY_N:
        return Keyboard::Type::N;
    case GLFW_KEY_O:
        return Keyboard::Type::O;
    case GLFW_KEY_P:
        return Keyboard::Type::P;
    case GLFW_KEY_Q:
        return Keyboard::Type::Q;
    case GLFW_KEY_R:
        return Keyboard::Type::R;
    case GLFW_KEY_S:
        return Keyboard::Type::S;
    case GLFW_KEY_T:
        return Keyboard::Type::T;
    case GLFW_KEY_U:
        return Keyboard::Type::U;
    case GLFW_KEY_V:
        return Keyboard::Type::V;
    case GLFW_KEY_W:
        return Keyboard::Type::W;
    case GLFW_KEY_X:
        return Keyboard::Type::X;
    case GLFW_KEY_Y:
        return Keyboard::Type::Y;
    case GLFW_KEY_Z:
        return Keyboard::Type::Z;
    case GLFW_KEY_UP:
        return Keyboard::Type::Up;
    case GLFW_KEY_DOWN:
        return Keyboard::Type::Down;
    case GLFW_KEY_LEFT:
        return Keyboard::Type::Left;
    case GLFW_KEY_RIGHT:
        return Keyboard::Type::Right;
    }
    return Keyboard::Type::Invalid;
}

static Keyboard::State convert_key_state(int key_state) {
    switch (key_state) {
    case GLFW_RELEASE:
        return Keyboard::State::Release;
    case GLFW_PRESS:
        return Keyboard::State::Push;
    case GLFW_REPEAT:
        return Keyboard::State::Hold;
    }
    return Keyboard::State::Invalid;
}

namespace keyboard_detail {

static Keyboard* keyboard_handler = nullptr;

void callback_impl(GLFWwindow*, int key_code, int, int action, int) {
    keyboard_handler->callback(key_code, action);
}

} // namespace keyboard_detail

Keyboard::Keyboard() {
    keyboard_detail::keyboard_handler = this;
}

void Keyboard::callback(int key_code, int action) {
    auto key = convert_key(key_code);
    auto state = convert_key_state(action);
    m_status[key] = state;
}

} // namespace mkyu


