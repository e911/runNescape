int gamePlay()
    {
        backgr bgr;

        play p;

        //Clip the sprite sheet
        p.set_clips();

        //The frame rate regulator
        Timer fps;

        //The stick figure
        play walk;
        //The timer starting time
//        timeshow t;
        while( quit == false )
            {
                //Start the frame timer

                fps.start();

                //While there's events to handle
                while( SDL_PollEvent( &event ) )
                    {

                       //Handle events for the stick figure
                        walk.handle_events();
                        //time_show();
                        //If the user has Xed out the window
                        if( event.type == SDL_QUIT )
                            {
                                //Quit the program
                                quit = true;
                            }
                    }

                bgr.scroll_backgr();
                bgr.show_backgr();

                //Show the stick figure on the screen
                walk.show();

                //Cap the frame rate
                if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                    {
                        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                    }

                //Update the screen
                if( SDL_Flip( screen ) ==-2 )
                    {
                        return 0;
                    }

            }
        //Clean up
        cleanUp();

        return 0;
    }

