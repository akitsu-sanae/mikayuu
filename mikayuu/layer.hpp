/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_LAYER_HPP
#define MIKAYUU_LAYER_HPP

#include <memory>
#include <vector>

namespace mkyu {

struct Scene;
struct DrawableObject;

struct Layer {
    Layer(mkyu::Scene const& p) :
        m_parent(p)
    {}
    virtual ~Layer() {}

    void update();

    std::vector<std::shared_ptr<mkyu::DrawableObject>> const& objects() const {
        return m_drawable_objects;
    }

    mkyu::Scene const& parent() const {
        return m_parent;
    }
protected:
    virtual void on_update() = 0;
    void add_object(std::shared_ptr<DrawableObject> const&);
private:
    std::vector<std::shared_ptr<mkyu::DrawableObject>> m_drawable_objects;
    mkyu::Scene const& m_parent;
};


}

#endif
