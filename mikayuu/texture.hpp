#ifndef MIKAYUU_TEXTURE_HPP
#define MIKAYUU_TEXTURE_HPP

// #include <png++/png.hpp>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/object.hpp>

namespace mkyu {

struct texture : mkyu::Object {
    explicit texture(std::string const& filename) {
        /*
        png::image<png::rgba_pixel> image(filename);
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        std::vector<unsigned char> buf;
        buf.reserve(image.get_width() * image.get_height());
        for (auto y = 0; y < image.get_height(); y++) {
            for (auto x = 0; x < image.get_width(); x++) {
                auto pix = image.get_pixel(x, y);
                buf.push_back(pix.red);
                buf.push_back(pix.green);
                buf.push_back(pix.blue);
            }
       }
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                     image.get_width(), image.get_height(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, buf.data());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        */
    }

    void draw() const override {
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-1.0, -1.0, 0.0);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(1.0, -1.0, 0.0);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(1.0, 1.0, 0.0);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(-1.0, 1.0, 0.0);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_TEXTURE_2D);
    }

    void update() override {}
    bool is_alive() override { return true; }
private:
    GLuint id;
};

}

#endif
