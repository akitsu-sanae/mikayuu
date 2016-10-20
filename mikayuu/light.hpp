#ifndef MIKAYUU_LIGHT_HPP
#define MIKAYUU_LIGHT_HPP

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/vector.hpp>
#include <mikayuu/color.hpp>

namespace mkyu {

struct light {
    void apply() const {
        const GLfloat pos_para[] = {
            (GLfloat)position.x, (GLfloat)position.y, (GLfloat)position.z,
            1.0
        };
        glLightfv(GL_LIGHT0, GL_POSITION, pos_para);
        const GLfloat light_color_para[] = {
            (GLfloat)light_color.r / 255.0,
            (GLfloat)light_color.g / 255.0,
            (GLfloat)light_color.b / 255.0
        };
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color_para);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_color_para);

        const GLfloat env_color_para[] = {
            (GLfloat)env_color.r / 255.0,
            (GLfloat)env_color.g / 255.0,
            (GLfloat)env_color.b / 255.0
        };
        glLightfv(GL_LIGHT0, GL_AMBIENT, env_color_para);
    }
    mkyu::vector3d position;
    mkyu::color light_color;
    mkyu::color env_color;
};

}

#endif
