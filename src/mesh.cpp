/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <fstream>
#include <GLFW/glfw3.h>
#include <mikayuu/mesh.hpp>

static void load_nodes(mkyu::Mesh& mesh, std::ifstream& input) {
    int n;
    input >> n;
    for (int i=0; i<n; i++) {
        mkyu::Node node;
        node.id = i;
        input >> node.x;
        input >> node.y;
        input >> node.z;
        mesh.add_node(node);
    }
}

static void load_faces(mkyu::Mesh& mesh, std::ifstream& input) {
    int n;
    input >> n;
    for (int i=0; i<n; i++) {
        mkyu::Face face;
        for (int d=0; d<3; d++)
            input >> face.node_ids.at(d);
        mesh.add_face(face);
    }
}

std::unique_ptr<mkyu::Mesh>
mkyu::Mesh::load(std::string const& filename)
{
    std::ifstream input(filename);
    if (!input)
        return nullptr;

    auto result = std::make_unique<mkyu::Mesh>(mkyu::vector2d{0.0, 0.0});

    while (!input.eof()) {
        int type;
        input >> type;
        if (type == 0)
            load_nodes(*result, input);
        else if (type == 1)
            load_faces(*result, input);
    }
    return result;
}

void mkyu::Mesh::draw() const {
    glBegin(GL_TRIANGLES);
    for (auto const& face : m_faces) {
        for (auto const& node_id: face.node_ids) {
            auto const& node = m_nodes.at(node_id);
            glVertex3d(node.x, node.y, node.z);
        }
    }
    glEnd();
}



