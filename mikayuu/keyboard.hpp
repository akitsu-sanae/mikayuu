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

struct Keyboard final {
    struct unknouwn_key_exception : std::exception {};

    static void set_window(GLFWwindow* win) {
        m_window = win;
    }
    static void update();
    static KeyState state(KeyType type);
private:
    static std::unordered_map<KeyType, KeyState> m_key_states;
    static GLFWwindow* m_window;
};

}

#endif

