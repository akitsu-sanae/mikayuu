#ifndef MIKAYUU_HPP
#define MIKAYUU_HPP

#include <GLFW/glfw3.h>
#include <mikayuu/utility.hpp>

namespace mkyu {

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
protected:
    virtual void on_update() = 0;
private:
    GLFWwindow* m_window = nullptr;
};

}




#endif
