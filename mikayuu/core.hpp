#ifndef MIKAYUU_HPP
#define MIKAYUU_HPP

#include <GLFW/glfw3.h>
#include <mikayuu/utility.hpp>
#include <memory>
#include <vector>
#include <mikayuu/drawable_object.hpp>

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
    void add_drawable_object(std::shared_ptr<DrawableObject> const&);
private:
    void draw() const;
    GLFWwindow* m_window = nullptr;
    std::vector<std::shared_ptr<mkyu::DrawableObject>> m_drawable_objects;
};

}




#endif
