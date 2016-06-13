#ifndef MIKAYUU_DRAWABLE_HP
#define MIKAYUU_DRAWABLE_HP

#include <mikayuu/vec.hpp>

namespace mkyu {

struct DrawableObject {
    explicit DrawableObject(vec2d const& position) :
        position(position)
    {}
    virtual ~DrawableObject() {}
    virtual void draw() const = 0;

    vec2d position;
};

}


#endif
