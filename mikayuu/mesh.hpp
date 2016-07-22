/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef MIKAYUU_MESH_HPP
#define MIKAYUU_MESH_HPP

#include <vector>
#include <memory>
#include <mikayuu/object.hpp>
#include <mikayuu/face.hpp>
#include <mikayuu/node.hpp>

namespace mkyu {

struct Mesh : public mkyu::Object {
    static std::unique_ptr<Mesh> load(std::string const&);
    virtual ~Mesh() = default;

    void update() override {}
    void draw() const override;

    void add_face(mkyu::Face const& face) {
        m_faces.push_back(face);
    }
    void add_node(mkyu::Node const& node) {
        m_nodes.push_back(node);
    }
private:
    std::vector<mkyu::Face> m_faces;
    std::vector<mkyu::Node> m_nodes;
};

}

#endif

