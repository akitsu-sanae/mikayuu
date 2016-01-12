#ifndef MIKAYUU_HPP
#define MIKAYUU_HPP

namespace mkyu {

struct Option {
    int width = 640;
    int height = 480;
    const char* title = "";
    bool is_fullscreen = false;
};


void initialize(Option const&);
int update();
void terminate();

}




#endif
