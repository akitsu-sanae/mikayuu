#ifndef MIKAYUU_HPP
#define MIKAYUU_HPP

#include <GLFW/glfw3.h>
#include <mikayuu/utility.hpp>
#include <memory>
#include <vector>
#include <mikayuu/drawable_object.hpp>

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

    void change_scene(std::shared_ptr<mkyu::Scene> const&);
protected:
    virtual void on_update() = 0;
private:
    GLFWwindow* m_window = nullptr;

    std::shared_ptr<Scene> m_current_scene;
    std::shared_ptr<Scene> m_next_scene;
};

}




#endif
