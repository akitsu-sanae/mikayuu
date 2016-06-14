/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_KEYBOARD_HPP
#define MIKAYUU_KEYBOARD_HPP

#include <string>
#include <map>

struct GLFWwindow;

namespace mkyu {

struct Keyboard {
    enum class KeyType {
        A, B, C, D, E, F, G, H, I, J, K, L, M,
        N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

        Zero, One, Two, Three, Four,
        Five, Six, Seven, Eight, Nine,

        Up, Down, Left, Right,

        Space, Enter,
        Shift, Ctrl,
        Escape,

        Invalid
    };
    enum class KeyState {
        Release,
        Push,
        Hold,

        Invalid
    };

    KeyState state(KeyType type) const {
        auto found = m_status.find(type);
        if (found == m_status.end())
            return KeyState::Invalid;
        return found->second;
    }

    explicit Keyboard();
    void callback(int, int);
private:
    std::map<KeyType, KeyState> m_status = {};
};

namespace keyboard_detail {
void callback_impl(GLFWwindow*, int, int, int, int);
}

}

#endif

