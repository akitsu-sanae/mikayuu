/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_GAME_HPP
#define MIKAYUU_GAME_HPP

#include <GLFW/glfw3.h>
#include <mikayuu/utility.hpp>
#include <mikayuu/keyboard.hpp>

namespace mkyu {

struct Scene;

struct Game {
    struct Option {
        int width = 640;
        int height = 480;
        const char* title = "";
        bool is_fullscreen = false;
    };

    explicit Game(mkyu::Game::Option const&);
    virtual ~Game();

    int update();

    void change_scene(mkyu::ptr<mkyu::Scene> const&);

    mkyu::Keyboard const& keyboard() const {
        return m_keyboard;
    }
protected:
    virtual void on_update() = 0;
private:
    GLFWwindow* m_window = nullptr;
    mkyu::Keyboard m_keyboard;

    mkyu::ptr<Scene> m_current_scene;
    mkyu::ptr<Scene> m_next_scene;
};

} // namespace mkyu

#endif
