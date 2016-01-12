#ifndef MIKAYUU_POLYGON_CONTAINER_HPP
#define MIKAYUU_POLYGON_CONTAINER_HPP

#include <vector>
#include <mikayuu/polygon.hpp>

namespace mkyu {

template<int N>
struct PolygonContainer {
    template<typename ... Types>
    void emplace_back(Types ... args) {
        m_objects.emplace_back(args ...);
    }
    void push_back(T const& t) {
        m_objects.push_back(t);
    }
    void draw() const {
        for (auto&& e : m_objects)
            e.draw_impl();
    }
    template<typename F>
    void for_each(F const& f) const {
        for (auto&& e : m_objects)
            f(e);
    }
private:
    std::vector<Polygon<N>> m_objects;
};

}

#endif
