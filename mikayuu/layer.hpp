/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_LAYER_HPP
#define MIKAYUU_LAYER_HPP

#include <mikayuu/utility.hpp>

namespace mkyu {

struct Scene;
struct Object;

struct Layer {
    Layer(mkyu::Scene const& p) :
        m_parent(p)
    {}
    virtual ~Layer() {}

    void update();

    mkyu::container<mkyu::Object> const& objects() const {
        return m_objects;
    }

    mkyu::Scene const& parent() const {
        return m_parent;
    }
protected:
    virtual void on_update() = 0;
    void add_object(mkyu::ptr<mkyu::Object> const&);
private:
    mkyu::container<mkyu::Object> m_objects;
    mkyu::Scene const& m_parent;
};


}

#endif
