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

namespace mkyu {

struct Mesh : public mkyu::Object {

    struct Face {
        explicit Face(unsigned int id, std::array<unsigned int, 3> const& node_ids) :
            id(id),
            node_ids(node_ids)
        {}
        unsigned int id;
        std::array<unsigned int, 3> node_ids;
    };
    struct Node {
        explicit Node(unsigned int id, mkyu::vector3d const& position) :
            id(id),
            position(position)
        {}
        unsigned int id;
        mkyu::vector3d position;
    };

    virtual ~Mesh() = default;
    void draw() const override final {
        glPushMatrix();
        glTranslated(position.x, position.y, position.z);
        glBegin(GL_TRIANGLES);
        glColor3b(255, 255, 255);
        for (auto const& face : m_faces) {
            for (auto const& node_id : face.node_ids) {
                auto const& node = m_nodes.at(node_id);
                glVertex3d(node.position.x, node.position.y, node.position.z);
            }
        }
        glEnd();
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

    struct mesh_loading_exception : public std::exception {
        explicit mesh_loading_exception(std::string const& msg) :
            message(msg)
        {}
        const char* what() const override {
            return message.c_str();
        }
        std::string message;
    };
    Mesh& read_from_file(std::string const& filename) {
        std::ifstream input(filename);
        while (true) {
            std::string type;
            input >> type;
            if (type == "nodes") {
                size_t n_of_nodes;
                input >> n_of_nodes;
                for (size_t i = 0; i < n_of_nodes; i++) {
                    mkyu::vector3d pos;
                    input >> pos.x >> pos.y >> pos.z;
                    m_nodes.emplace_back(i, pos);
                }
            } else if (type == "faces") {
                size_t n_of_faces;
                input >> n_of_faces;
                m_faces.reserve(m_faces.size() + n_of_faces);
                for (size_t i = 0; i < n_of_faces; i++) {
                    std::array<unsigned int, 3> node_ids;
                    input >> node_ids[0] >> node_ids[1] >> node_ids[2];
                    m_faces.emplace_back(i, node_ids);
                }
            } else if (type == "end") {
                break;
            } else {
                throw mesh_loading_exception{ "undefined type: " + type };
            }
        }
        return *this;
    }
private:
    std::vector<mkyu::Mesh::Face> m_faces;
    std::vector<mkyu::Mesh::Node> m_nodes;
};

}

#endif

