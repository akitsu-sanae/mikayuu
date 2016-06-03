#ifndef MIKAYUU_KEYBOARD_HPP
#define MIKAYUU_KEYBOARD_HPP

#include <string>
#include <array>

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
        return m_status.at(static_cast<int>(type));
    }

    explicit Keyboard();
    void callback(int, int);
private:
    std::array<KeyState, static_cast<int>(Keyboard::KeyType::Invalid)> m_status = {};
};

namespace keyboard_detail {
void callback_impl(GLFWwindow*, int, int, int, int);
}

}

#endif

