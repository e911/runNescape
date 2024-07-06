#ifndef TIMESHOW_H
#define TIMESHOW_H

#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include <string>
#include <sstream>
class timeshow
{
private:
    Uint32 start;
    public:
        timeshow();
        void tick();
        void showtime();
    void handle();
};

#endif // TIMESHOW_H
