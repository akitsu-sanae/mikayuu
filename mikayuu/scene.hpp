#ifndef MIKAYUU_SCENE_HPP
#define MIKAYUU_SCENE_HPP

#include <memory>
#include <vector>


namespace mkyu {

struct Game;
struct Layer;

struct Scene {
    Scene(mkyu::Game const& p) :
        m_parent(p)
    {}
    virtual ~Scene() {}

    void update();

    std::vector<std::shared_ptr<mkyu::Layer>> const& layers() const {
        return m_layers;
    }
protected:
    virtual void on_update() = 0;
    void add_layer(std::shared_ptr<mkyu::Layer> const&);
private:
    std::vector<std::shared_ptr<mkyu::Layer>> m_layers;
    mkyu::Game const& m_parent;
};

}

#endif
