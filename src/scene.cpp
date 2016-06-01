#include <mikayuu/scene.hpp>
#include <mikayuu/core.hpp>
#include <mikayuu/layer.hpp>

void mkyu::Scene::update() {
    on_update();

    for (auto&& l : m_layers)
        l->update();
}

void mkyu::Scene::add_layer(std::shared_ptr<mkyu::Layer> const& layer) {
    m_layers.push_back(layer);
}

