/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_CONTAINER_HPP
#define MIKAYUU_CONTAINER_HPP

#include <vector>
#include <mikayuu/object.hpp>
#include <mikayuu/utility.hpp>

namespace mkyu {

struct Container final : public mkyu::Object {

    template<typename T, typename ... Args>
    void add(Args&& ... args) {
        m_objects.push_back(std::make_unique<T>(std::forward<Args>(args) ...));
    }
    void update() override {
        for (auto&& obj: m_objects)
            obj->update();
    }
    void draw() const override {
        for (auto const& e : m_objects)
            e->draw();
    }
    bool is_alive() override {
        for (auto const& e : m_objects) {
            if (e->is_alive())
                return true;
        }
        return false;
    }

    template<typename F>
    void for_each(F const& f) const {
        for (auto&& e : m_objects)
            f(e);
    }

    auto begin() {
        return m_objects.begin();
    }
    auto begin() const {
        return m_objects.begin();
    }
    auto cbegin() const {
        return m_objects.begin();
    }
    auto end() {
        return m_objects.end();
    }
    auto end() const {
        return m_objects.end();
    }
    auto cend() const {
        return m_objects.end();
    }
private:
    util::container<mkyu::Object> m_objects;
};

}

#endif
