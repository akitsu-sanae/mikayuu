#ifndef MIKAYUU_KEYBOARD_HPP
#define MIKAYUU_KEYBOARD_HPP

#include <string>
#include <array>

struct GLFWwindow;

namespace mkyu {

enum class Key {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    X,
    Y,
    Z,

    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Size,
    Seven,
    Eight,
    Nine,

    Space,
    Esc,
    Enter,
    Shift,
    Ctrl,

    Up,
    Down,
    Left,
    Right,

    Invalid
};


enum class KeyState {
    Release,
    Push,
    Hold,

    Invalid
};

KeyState keyboard(Key);

namespace detail {

struct Keyboard {
    static void initialize() {};
    static void terminate() {}
    static KeyState get(Key key);
    static void set(Key key, KeyState state);
private:
    static std::array<KeyState, static_cast<int>(Key::Invalid)> states;
};

void keyboard_callback(GLFWwindow*, int, int, int, int);
}


}

#endif

