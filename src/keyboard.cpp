#include <array>
#include <GLFW/glfw3.h>
#include <mikayuu/keyboard.hpp>

namespace mkyu {

static Key convert_key(int key) {
    switch(key) {
    case GLFW_KEY_A:
        return Key::A;
    case GLFW_KEY_B:
        return Key::B;
    case GLFW_KEY_C:
        return Key::C;
    case GLFW_KEY_D:
        return Key::D;
    case GLFW_KEY_E:
        return Key::E;
    case GLFW_KEY_F:
        return Key::F;
    case GLFW_KEY_G:
        return Key::G;
    case GLFW_KEY_H:
        return Key::H;
    case GLFW_KEY_I:
        return Key::I;
    case GLFW_KEY_J:
        return Key::J;
    case GLFW_KEY_K:
        return Key::K;
    case GLFW_KEY_L:
        return Key::L;
    case GLFW_KEY_M:
        return Key::M;
    case GLFW_KEY_X:
        return Key::X;
    case GLFW_KEY_Z:
        return Key::Z;
    case GLFW_KEY_UP:
        return Key::Up;
    case GLFW_KEY_DOWN:
        return Key::Down;
    case GLFW_KEY_LEFT:
        return Key::Left;
    case GLFW_KEY_RIGHT:
        return Key::Right;
    }
    return Key::Invalid;
}

static KeyState convert_key_state(int key_state) {
    switch (key_state) {
    case GLFW_RELEASE:
        return KeyState::Release;
    case GLFW_PRESS:
        return KeyState::Push;
    case GLFW_REPEAT:
        return KeyState::Hold;
    }
    return KeyState::Invalid;
}


KeyState keyboard(Key key) {
    return detail::Keyboard::get(key);
}

namespace detail {

std::array<KeyState, static_cast<int>(Key::Invalid)> Keyboard::states = {};

KeyState Keyboard::get(Key key) {
    return states[static_cast<int>(key)];
}

void Keyboard::set(Key key, KeyState state) {
    states[static_cast<int>(key)] = state;
}

void keyboard_callback(GLFWwindow*, int key_code, int, int action, int) {
    Key key = convert_key(key_code);
    KeyState state = convert_key_state(action);
    Keyboard::set(key, state);
}

}

}
