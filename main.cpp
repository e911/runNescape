//Includes and header files
#include <iostream>
#include <cstring>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"


#include "constants.h"
#include "variables.h"
#include "blitCoordinates.h"
#include "initAll.h"
#include "cleanUp.h"
#include "Framerate.h"
#include "backgroundAnimation.h"
//#include "timeshow.h"
#include "stickAnimation.h"


#include "gamePlay.h"
#include "startMenu.h"

using namespace std;

int main( int argc, char* args[] )

    {

        if(!initAll())
            return 1;

        if(!loadFiles())
            return 1;

        startMenu();

        return 0;
    }
