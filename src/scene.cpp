#include <mikayuu/scene.hpp>
#include <mikayuu/core.hpp>
#include <mikayuu/drawable_object.hpp>


void mkyu::Scene::update() {
    on_update();
    draw();
}

void mkyu::Scene::add_drawable_object(std::shared_ptr<DrawableObject> const& obj) {
    m_drawable_objects.push_back(obj);
}

void mkyu::Scene::draw() const {
    for (auto&& e : m_drawable_objects)
        e->draw();
}



