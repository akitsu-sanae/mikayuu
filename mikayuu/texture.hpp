#ifndef MIKAYUU_TEXTURE_HPP
#define MIKAYUU_TEXTURE_HPP

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/object.hpp>

namespace mkyu {

namespace detail {

inline static GLuint create_shader() {
    GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    auto vertex_shader = R"#(
    attribute vec3 position;
    attribute vec2 uv;
    varying vec2 vuv;
    void main() {
        gl_Position = vec4(position, 1.0);
        vuv = uv;
    }
)#";
    glShaderSource(vertex_shader_id, 1, &vertex_shader, nullptr);
    glCompileShader(vertex_shader_id);
    GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

    auto fragment_shader = R"#(
    varying vec2 vuv;
    uniform sampler2D texture;
    void main() {
        gl_FragColor = texture2D(texture, vuv);
    }
)#";
    glShaderSource(fragment_shader_id, 1, &fragment_shader, nullptr);
    glCompileShader(fragment_shader_id);

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);
    glUseProgram(program_id);
    return program_id;
}

}

struct Texture : mkyu::Object {
    explicit Texture(std::string const& filename) {
        glGenTextures(1, &m_id);

        std::ifstream input(filename, std::ios::binary);
        const size_t filesize = static_cast<size_t>(input.seekg(0, input.end).tellg());
        input.seekg(0, input.beg);
        std::vector<char> buffer;
        buffer.resize(filesize);
        input.read(buffer.data(), filesize);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer.data());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void draw() const override {
        float vertex_position[] = {
            0.5f, 0.5f,
            -0.5f, 0.5f,
            -0.5f, -0.5f,
            0.5f, -0.5f
        };
        const GLfloat uv[] = {
            1, 0,
            0, 0,
            0, 1,
            1, 1
        };
        int position_location = glGetAttribLocation(program_id, "position");
        int uv_location = glGetAttribLocation(program_id, "uv");
        int texture_location = glGetUniformLocation(program_id, "texture");

        glEnableVertexAttribArray(position_location);
        glEnableVertexAttribArray(uv_location);

        glUniform1i(texture_location, 0);

        glVertexAttribPointer(position_location, 2, GL_FLOAT, false, 0, vertex_position);
        glVertexAttribPointer(uv_location, 2, GL_FLOAT, false, 0, uv);

        glBindTexture(GL_TEXTURE_2D, m_id);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }

    void update() override {}
    bool is_alive() override { return true; }
private:
    GLuint m_id;
};

}

#endif
