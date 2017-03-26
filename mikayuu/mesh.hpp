/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef MIKAYUU_MESH_HPP
#define MIKAYUU_MESH_HPP

#include <array>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <exception>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/object.hpp>
#include <mikayuu/utility.hpp>

namespace mkyu {

struct Mesh : public mkyu::Object {
    struct Face {
        std::array<GLuint, 3> node_ids;
    };
    struct Node {
        vector3 position;
    };

    explicit Mesh(const char* filename) {
        std::ifstream input{filename};
        std::string line;
        while (std::getline(input, line)) {
            auto data = util::split(line);
            if (data[0][0] == '#')
                continue;
            if (data[0] == "v") {
                auto pos_arr = util::range<std::string>{data, 1, data.size()}
                    .map([&](std::string const& str) {
                        return (float)std::stod(str);
                    }).to_array<3>();
               auto pos = vector3{pos_arr};
               m_nodes.push_back(Node{pos});
                continue;
            }
            if (data[0] == "f") {
                auto node_ids = util::range<std::string>{data, 1, data.size()}
                    .map([&](std::string const& str) {
                        return (unsigned int)std::stoul(str) - 1;
                    }).to_array<3>();
                m_faces.push_back(Face{node_ids});
            }
        }
    }

    virtual ~Mesh() = default;

    void draw() const override final {
        glPushMatrix();
        glTranslated(position.x, position.y, position.z);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, &m_nodes[0].position[0]);
        glDrawElements(GL_TRIANGLES, m_faces.size() * 3, GL_UNSIGNED_INT, &m_faces[0].node_ids[0]);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopMatrix();
    }

    std::vector<mkyu::Mesh::Face>& faces() {
        return m_faces;
    }
    std::vector<mkyu::Mesh::Face> const& faces() const {
        return m_faces;
    }
    std::vector<mkyu::Mesh::Node>& nodes() {
        return m_nodes;
    }
    std::vector<mkyu::Mesh::Node> const& nodes() const {
        return m_nodes;
    }
private:
    std::vector<Face> m_faces;
    std::vector<Node> m_nodes;
};

}

#endif

