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

static Keyboard::KeyType convert_key(int key) {
    switch(key) {
    case GLFW_KEY_A:
        return Keyboard::KeyType::A;
    case GLFW_KEY_B:
        return Keyboard::KeyType::B;
    case GLFW_KEY_C:
        return Keyboard::KeyType::C;
    case GLFW_KEY_D:
        return Keyboard::KeyType::D;
    case GLFW_KEY_E:
        return Keyboard::KeyType::E;
    case GLFW_KEY_F:
        return Keyboard::KeyType::F;
    case GLFW_KEY_G:
        return Keyboard::KeyType::G;
    case GLFW_KEY_H:
        return Keyboard::KeyType::H;
    case GLFW_KEY_I:
        return Keyboard::KeyType::I;
    case GLFW_KEY_J:
        return Keyboard::KeyType::J;
    case GLFW_KEY_K:
        return Keyboard::KeyType::K;
    case GLFW_KEY_L:
        return Keyboard::KeyType::L;
    case GLFW_KEY_M:
        return Keyboard::KeyType::M;
    case GLFW_KEY_X:
        return Keyboard::KeyType::X;
    case GLFW_KEY_Z:
        return Keyboard::KeyType::Z;
    case GLFW_KEY_UP:
        return Keyboard::KeyType::Up;
    case GLFW_KEY_DOWN:
        return Keyboard::KeyType::Down;
    case GLFW_KEY_LEFT:
        return Keyboard::KeyType::Left;
    case GLFW_KEY_RIGHT:
        return Keyboard::KeyType::Right;
    }
    return Keyboard::KeyType::Invalid;
}

static Keyboard::KeyState convert_key_state(int key_state) {
    switch (key_state) {
    case GLFW_RELEASE:
        return Keyboard::KeyState::Release;
    case GLFW_PRESS:
        return Keyboard::KeyState::Push;
    case GLFW_REPEAT:
        return Keyboard::KeyState::Hold;
    }
    return Keyboard::KeyState::Invalid;
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


