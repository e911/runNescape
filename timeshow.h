/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers

#include <string>
#include <sstream>
class timeshow{
private:

    Uint32 start;

public:
    timeshow()
    {
        start=0;
    }
void time_show()
    {


              int  start=SDL_GetTicks();

            //The timer's time as a string
            std::stringstream time;

            //Convert the timer's time to a string
            time << "Timer: " << (SDL_GetTicks()-start)/1000;

            //Render the time surface
            seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor );

            //Apply the time surface
            apply_surface( ( SCREEN_WIDTH - seconds->w ) / 2, 50, seconds, screen );

            //SDL_FreeSurface(seconds);

    }
};
