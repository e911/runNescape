
//The surfaces
SDL_Surface *stickMan = NULL;
SDL_Surface *menu = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *obst = NULL;
SDL_Surface *obst2 = NULL;

//The event structure
SDL_Event event;

//The areas of the sprite sheet
SDL_Rect clipsRight[ 7 ];
SDL_Rect clipsUp[ 7 ];
SDL_Rect clipsR[ 7 ];
SDL_Rect box;
SDL_Rect box1;
//The surfaces

SDL_Surface *startStop = NULL;
SDL_Surface *seconds = NULL;
SDL_Surface *scrs = NULL;
//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

