
bool initAll()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }
  //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }
    //Set the window caption
    SDL_WM_SetCaption( "Run & Escape", NULL );

    //If everything initialized fine
    return true;
}
SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}
bool loadFiles()
{
    //Load the sprite sheet
     font = TTF_OpenFont( "lazy.ttf", 36 );
    stickMan = load_image( "Sprite.png" );
 obst = load_image( "obst.png" );
  obst2 = load_image( "obst2.png" );
menu = load_image ("menuSprite.png");
   background = load_image( "background.bmp" );
    //If there was a problem in loading the sprite
    if( stickMan == NULL || background == NULL ||obst== NULL || obst== NULL ||menu== NULL||font==NULL )
    {
        return false;
    }

    //If everything loaded fine

    return true;
}


