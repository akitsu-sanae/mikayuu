#ifndef MIKAYUU_SCENE_HPP
#define MIKAYUU_SCENE_HPP

#include <memory>
#include <vector>


namespace mkyu {

struct Game;
struct DrawableObject;

struct Scene {
    Scene(std::shared_ptr<mkyu::Game> const& p) :
        m_parent(p)
    {}
    virtual ~Scene() {}

    void update();
protected:
    virtual void on_update() = 0;
    void add_drawable_object(std::shared_ptr<DrawableObject> const&);
private:
    void draw() const;

    std::vector<std::shared_ptr<mkyu::DrawableObject>> m_drawable_objects;
    std::shared_ptr<mkyu::Game> m_parent;
};

}

#endif
