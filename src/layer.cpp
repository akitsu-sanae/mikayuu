#include <mikayuu/layer.hpp>
#include <mikayuu/drawable_object.hpp>

void mkyu::Layer::update() {
    on_update();

    for (auto&& o : m_drawable_objects)
        o->draw();
}

void mkyu::Layer::add_object(std::shared_ptr<mkyu::DrawableObject> const& obj) {
    m_drawable_objects.push_back(obj);
}


