void cleanUp()
{
    //Free the surface
    SDL_FreeSurface( stickMan );
    SDL_FreeSurface( background );
 SDL_FreeSurface( screen );
 SDL_FreeSurface( menu);
 SDL_FreeSurface( startStop );

    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();
    //Quit SDL
    SDL_Quit();
}

