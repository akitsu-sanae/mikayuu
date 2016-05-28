#ifndef MIKAYUU_DRAWABLE_HP
#define MIKAYUU_DRAWABLE_HP

namespace mkyu {

struct DrawableObject {
    virtual ~DrawableObject() {}
    virtual void draw() const = 0;
};

}


#endif
