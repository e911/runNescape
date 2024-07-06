int startMenu( )
    {
        backgr bgr;

        //The frame rate regulator
        Timer fps;

        //While the user hasn't quit
        while( quit == false )
            {
                //Start the frame timer
                fps.start();

                //While there's events to handle
                while( SDL_PollEvent( &event ) )
                    {
                        //If the user has Xed out the window
                        if( event.type == SDL_QUIT )
                            {
                                //Quit the program
                                quit = true;
                            }
                    }

                bgr.scroll_backgr();
                bgr.show_backgr();

                //Show the menu
                apply_surface( 338, 135, menu, screen );

                //Update the screen
                if( SDL_Flip( screen ) == -1 )
                    {
                        return 1;
                    }

                //Cap the frame rate
                if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                    {
                        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );

                    }

                if(event.type == SDL_MOUSEBUTTONDOWN)
                    {
                        int x = event.motion.x;
                        int y = event.motion.y;
                            if((x>375) && (x<558) && (y>210) && (y<249))
                                {
                                    gamePlay();

                                }
                            /*else if((x>375) && (x<558) && (y>260) && (y<299))
                                {
                                    apply_surface(0,0,options_menu,screen);
                            }*/
                    }
            }

        //Clean up
        cleanUp();

        return 0;
    }

