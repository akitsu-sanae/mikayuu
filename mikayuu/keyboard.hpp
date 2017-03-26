/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_KEYBOARD_HPP
#define MIKAYUU_KEYBOARD_HPP

#include <string>
#include <unordered_map>

struct GLFWwindow;

namespace mkyu {

enum class KeyType {
    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

    Down, Up, Left, Right,

    Space
};

enum class KeyState {
    Release,
    Push,
    Hold
};
} // end of mkyu

namespace std {

template<>
struct hash<mkyu::KeyType> {
    size_t operator()(mkyu::KeyType type) const noexcept {
        return hash<size_t>{}(static_cast<size_t>(type));
    }
};

}

namespace mkyu {

namespace detail {

static int convert_key(KeyType type) {
    switch (type) {
    case KeyType::A:
        return GLFW_KEY_A;
    case KeyType::B:
        return GLFW_KEY_B;
    case KeyType::C:
        return GLFW_KEY_C;
    case KeyType::D:
        return GLFW_KEY_D;
    case KeyType::E:
        return GLFW_KEY_E;
    case KeyType::F:
        return GLFW_KEY_F;
    case KeyType::G:
        return GLFW_KEY_G;
    case KeyType::H:
       return GLFW_KEY_H;
    case KeyType::I:
        return GLFW_KEY_I;
    case KeyType::J:
        return GLFW_KEY_J;
    case KeyType::K:
        return GLFW_KEY_K;
    case KeyType::L:
       return GLFW_KEY_L;
    case KeyType::M:
        return GLFW_KEY_M;
    case KeyType::N:
        return GLFW_KEY_N;
    case KeyType::O:
        return GLFW_KEY_O;
    case KeyType::P:
        return GLFW_KEY_P;
    case KeyType::Q:
       return GLFW_KEY_Q;
    case KeyType::R:
        return GLFW_KEY_R;
    case KeyType::S:
        return GLFW_KEY_S;
    case KeyType::T:
        return GLFW_KEY_T;
    case KeyType::U:
        return GLFW_KEY_U;
    case KeyType::V:
        return GLFW_KEY_V;
    case KeyType::W:
        return GLFW_KEY_W;
    case KeyType::X:
        return GLFW_KEY_X;
    case KeyType::Y:
        return GLFW_KEY_Y;
    case KeyType::Z:
        return GLFW_KEY_Z;
    case KeyType::Down:
        return GLFW_KEY_DOWN;
    case KeyType::Up:
        return GLFW_KEY_UP;
    case KeyType::Left:
        return GLFW_KEY_LEFT;
    case KeyType::Right:
        return GLFW_KEY_RIGHT;
    case KeyType::Space:
        return GLFW_KEY_SPACE;
    default:
        throw std::logic_error{"invalid key type"};
    }
}

} // end of detail

struct Keyboard final {
    explicit Keyboard(GLFWwindow const* window) :
        m_window{window}
    {}
    void update() {
        auto update = [&](KeyType key) {
            bool is_pressed = glfwGetKey(const_cast<GLFWwindow*>(m_window), detail::convert_key(key)) == GLFW_PRESS;
                if (!is_pressed)
                    m_key_states[key] = KeyState::Release;
                else if (m_key_states[key] == KeyState::Release)
                    m_key_states[key] = KeyState::Push;
                else
                    m_key_states[key] = KeyState::Hold;
        };
        for (int i = 0; i <= static_cast<int>(KeyType::Space); i++) {
            update(static_cast<KeyType>(i));
        }
    }
    KeyState state(KeyType type) const {
        auto it = m_key_states.find(type);
        if (it == m_key_states.end())
            throw std::logic_error{"invalid key"};
        return it->second;
    }
private:
    GLFWwindow const* m_window;
    std::unordered_map<KeyType, KeyState> m_key_states;
};

} // end of mkyu

#endif

