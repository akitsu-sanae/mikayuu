/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <array>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <mikayuu/keyboard.hpp>
#include <mikayuu/object.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/color.hpp>
#include <mikayuu/mesh.hpp>
#include <mikayuu/object.hpp>
#include <mikayuu/layer.hpp>
#include <mikayuu/scene.hpp>
#include <mikayuu/game.hpp>
#include <mikayuu/texture.hpp>
#include <mikayuu/detail.hpp>

namespace mkyu {

GLFWwindow* detail::window = nullptr;
mkyu::vector<int, 2> detail::size = mkyu::vector<int, 2>{};
std::unordered_map<KeyType, KeyState> Keyboard::m_key_states;

void detail::apply_camera(mkyu::camera const& camera) {
    glLoadIdentity();
    glViewport(camera.distination[0], camera.distination[1], camera.distination[2], camera.distination[3]);
    gluPerspective(30.0, (double)camera.distination[2] / (double)camera.distination[3], 0.1, 100.0);
    gluLookAt(
        camera.origin_position.x, camera.origin_position.y, camera.origin_position.z,
        camera.target_position.x, camera.target_position.y, camera.target_position.z,
        camera.up_direction.x, camera.up_direction.y, camera.up_direction.z
    );
}

void detail::apply_light(mkyu::light const& light) {
    const GLfloat pos_para[] = {
        (GLfloat)light.position.x, (GLfloat)light.position.y, (GLfloat)light.position.z,
        1.0
    };
    glLightfv(GL_LIGHT0, GL_POSITION, pos_para);
    const GLfloat light_color_para[] = {
        (GLfloat)light.light_color.r / 255.0,
        (GLfloat)light.light_color.g / 255.0,
        (GLfloat)light.light_color.b / 255.0
    };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color_para);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_color_para);

    const GLfloat env_color_para[] = {
        (GLfloat)light.env_color.r / 255.0,
        (GLfloat)light.env_color.g / 255.0,
        (GLfloat)light.env_color.b / 255.0
    };
    glLightfv(GL_LIGHT0, GL_AMBIENT, env_color_para);
}

void detail::apply_object_setting(mkyu::Object const& obj) {
    std::array<GLfloat, 3> v = {{
            static_cast<GLfloat>(obj.color.r) / 255.f,
            static_cast<GLfloat>(obj.color.g) / 255.f,
            static_cast<GLfloat>(obj.color.b) / 255.f,
        }};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, v.data());
    if (obj.blend_mode == Object::BlendMode::None) {
        glDisable(GL_BLEND);
        return;
    }

    glEnable(GL_BLEND);

    switch (obj.blend_mode) {
    case Object::BlendMode::None:
        break;
    case Object::BlendMode::Alpha:
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        break;
    case Object::BlendMode::Reverse:
        glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
        break;
    case Object::BlendMode::Add:
        glBlendFunc(GL_ONE, GL_ONE);
        break;
    case Object::BlendMode::Screen:
        glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
        break;
    case Object::BlendMode::Mult:
        glBlendFunc(GL_ZERO, GL_SRC_COLOR);
        break;
    }
}

static int convert_key(KeyType type) {
    switch (type) {
    case KeyType::A:
        return GLFW_KEY_A;
    case KeyType::B:
        return GLFW_KEY_B;
    case KeyType::C:
        return GLFW_KEY_C;
    case KeyType::D:
        return GLFW_KEY_D;
    case KeyType::E:
        return GLFW_KEY_E;
    case KeyType::F:
        return GLFW_KEY_F;
    case KeyType::G:
        return GLFW_KEY_G;
    case KeyType::H:
        return GLFW_KEY_H;
    case KeyType::I:
        return GLFW_KEY_I;
    case KeyType::J:
        return GLFW_KEY_J;
    case KeyType::K:
        return GLFW_KEY_K;
    case KeyType::L:
        return GLFW_KEY_L;
    case KeyType::M:
        return GLFW_KEY_M;
    case KeyType::N:
        return GLFW_KEY_N;
    case KeyType::O:
        return GLFW_KEY_O;
    case KeyType::P:
        return GLFW_KEY_P;
    case KeyType::Q:
        return GLFW_KEY_Q;
    case KeyType::R:
        return GLFW_KEY_R;
    case KeyType::S:
        return GLFW_KEY_S;
    case KeyType::T:
        return GLFW_KEY_T;
    case KeyType::U:
        return GLFW_KEY_U;
    case KeyType::V:
        return GLFW_KEY_V;
    case KeyType::W:
        return GLFW_KEY_W;
    case KeyType::X:
        return GLFW_KEY_X;
    case KeyType::Y:
        return GLFW_KEY_Y;
    case KeyType::Z:
        return GLFW_KEY_Z;

    case KeyType::Down:
        return GLFW_KEY_DOWN;
    case KeyType::Up:
        return GLFW_KEY_UP;
    case KeyType::Left:
        return GLFW_KEY_LEFT;
    case KeyType::Right:
        return GLFW_KEY_RIGHT;
    case KeyType::Space:
        return GLFW_KEY_SPACE;
    default:
        throw std::logic_error{"invalid key type"};
    }
}

void mkyu::Keyboard::update() {
    auto update = [](KeyType key) {
        bool is_pressed = glfwGetKey(detail::window, convert_key(key)) == GLFW_PRESS;
        if (!is_pressed)
            m_key_states[key] = KeyState::Release;
        else if (m_key_states[key] == KeyState::Release)
            m_key_states[key] = KeyState::Push;
        else
            m_key_states[key] = KeyState::Hold;
    };
    for (int i = 0; i <= static_cast<int>(KeyType::Space); i++) {
        update(static_cast<KeyType>(i));
    }
}

KeyState Keyboard::state(KeyType key) {
    auto it = m_key_states.find(key);
    if (it == m_key_states.end())
        throw unknouwn_key_exception{};
    return it->second;
}

} // namespace mkyu


