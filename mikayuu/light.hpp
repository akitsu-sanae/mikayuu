#ifndef MIKAYUU_LIGHT_HPP
#define MIKAYUU_LIGHT_HPP

#include <mikayuu/vector.hpp>
#include <mikayuu/color.hpp>

namespace mkyu {

struct light {
    mkyu::vector3 position;
    mkyu::color light_color;
    mkyu::color env_color;
};

}

#endif
