#include "obst.h"
#include "collision.h"
//The stick figure
class play
    {
        private:

            //Its rate of movement
            int velocity;

            //Its current frame
            int frame;

            //Its animation status
            int status;

            obstacle obj;
            Uint32  start;
            int scr;
bool running;

        public:

            //Initializes the variables
            play();

            void set_clips();

            //Handles input
            void handle_events();

            //Shows the stick figure
            void show();
    };


void play::set_clips()
    {
        //Clip the sprites

        //clips for run
        clipsRight[ 0 ].x = 0;
        clipsRight[ 0 ].y = STICK_HEIGHT_JUMP;
        clipsRight[ 0 ].w = STICK_WIDTH_RUN;
        clipsRight[ 0 ].h = STICK_HEIGHT_RUN;

        clipsRight[ 1 ].x = STICK_WIDTH_RUN;
        clipsRight[ 1 ].y = STICK_HEIGHT_JUMP;
        clipsRight[ 1 ].w = STICK_WIDTH_RUN;
        clipsRight[ 1 ].h = STICK_HEIGHT_RUN;

        clipsRight[ 2 ].x = STICK_WIDTH_RUN * 2;
        clipsRight[ 2 ].y = STICK_HEIGHT_JUMP;
        clipsRight[ 2 ].w = STICK_WIDTH_RUN;
        clipsRight[ 2 ].h = STICK_HEIGHT_RUN;

        clipsRight[ 3 ].x = STICK_WIDTH_RUN * 3;
        clipsRight[ 3 ].y = STICK_HEIGHT_JUMP;
        clipsRight[ 3 ].w = STICK_WIDTH_RUN;
        clipsRight[ 3 ].h = STICK_HEIGHT_RUN;

        clipsRight[ 4 ].x = 0;
        clipsRight[ 4 ].y = STICK_HEIGHT_JUMP;
        clipsRight[ 4 ].w = STICK_WIDTH_RUN;
        clipsRight[ 4].h = STICK_HEIGHT_RUN;

        clipsRight[ 5].x = STICK_WIDTH_RUN;
        clipsRight[ 5 ].y = STICK_HEIGHT_JUMP;
        clipsRight[ 5].w = STICK_WIDTH_RUN;
        clipsRight[ 5].h = STICK_HEIGHT_RUN;

        clipsRight[ 6 ].x = STICK_WIDTH_RUN * 2;
        clipsRight[ 6].y = STICK_HEIGHT_JUMP;
        clipsRight[ 6].w = STICK_WIDTH_RUN;
        clipsRight[ 6 ].h = STICK_HEIGHT_RUN;

        //clips for jump
       for(int i=0;i<=6;i++)
            {
                clipsUp[ i ].x = STICK_WIDTH_JUMP*i;
                clipsUp[ i ].y = 0;
                clipsUp[ i ].w = STICK_WIDTH_JUMP;
                clipsUp[ i ].h = STICK_HEIGHT_JUMP;
            }

            /*
        clipsUp[0].x=0;
        clipsUp[0].y=212;
        clipsUp[0].w=77;
        clipsUp[0].h=90;

         clipsUp[1].x=73;
        clipsUp[1].y=109;
        clipsUp[1].w=77;
        clipsUp[1].h=118;

         clipsUp[2].x=150;
        clipsUp[2].y=52;
        clipsUp[2].w=77;
        clipsUp[2].h=118;

         clipsUp[3].x=239;
        clipsUp[3].y=4;
        clipsUp[3].w=77;
        clipsUp[3].h=93;

         clipsUp[4].x=313;
        clipsUp[4].y=43;
        clipsUp[4].w=77;
        clipsUp[4].h=118;

         clipsUp[5].x=387;
        clipsUp[5].y=113;
        clipsUp[5].w=77;
        clipsUp[5].h=118;

         clipsUp[6].x=463;
        clipsUp[6].y=198;
        clipsUp[6].w=77;
        clipsUp[6].h=106;*/

    clipsR[0].x=0;
    clipsR[0].y=411;
    clipsR[0].w=79;
    clipsR[0].h=114;

     clipsR[1].x=79;
    clipsR[1].y=411;
    clipsR[1].w=67;
    clipsR[1].h=114;

 clipsR[2].x=146;
    clipsR[2].y=411;
    clipsR[2].w=106;
    clipsR[2].h=114;

 clipsR[3].x=252;
    clipsR[3].y=411;
    clipsR[3].w=84;
    clipsR[3].h=114;

 clipsR[4].x=336;
    clipsR[4].y=411;
    clipsR[4].w=95;
    clipsR[4].h=114;

 clipsR[5].x=431;
    clipsR[5].y=411;
    clipsR[5].w=55;
    clipsR[5].h=114;

 clipsR[6].x=486;
    clipsR[6].y=411;
    clipsR[6].w=70;
    clipsR[6].h=114;



    }

play::play()
    {
        //Initialize movement variables
        velocity = 0;
start=0;scr=1;
        //Initialize animation variables
        frame = 0;

        status = STICK_RIGHT;
running=true;
    }

void play::handle_events()
    {
        //If a key was pressed
        if( event.type == SDL_KEYDOWN )
            {
                //Set the velocity
                switch( event.key.keysym.sym )
                    {
                        case SDLK_RIGHT: velocity = STICK_WIDTH_RUN / 8; break;
                        case SDLK_UP: velocity =- STICK_WIDTH_JUMP / 8 ; break;
                        case SDLK_DOWN: velocity = 50 ; break;


                        default:  break;
                    }
            }
    }



void play::show()
    {
        //If stickman is moving up
        if( (velocity ==STICK_WIDTH_RUN / 8))
            {
                //Set the animation to up
                status = STICK_RIGHT;

                //Move to the next frame in the animation
                frame++;
            }

        //If stickman is moving right
        else if( (velocity == -STICK_WIDTH_JUMP /8))
            {
                //Set the animation to right
                status = STICK_UP;

                //Move to the next frame in the animation
              frame++;
            }
  else if( (velocity == 50))
            {
                //Set the animation to right
                status = STICK_ROLL;

                //Move to the next frame in the animation
              frame++;
            }

        //If stickman standing
       else
            {
                //Restart the animation
                frame = 0;
                velocity =STICK_WIDTH_RUN / 8;
            }

        //Loop the animation
      if( frame >6  )
            {
                frame = 0;
                velocity =STICK_WIDTH_RUN / 8;
            }

        //Show the stickman
        if( status == STICK_RIGHT )
            {
                apply_surface( 25, SCREEN_HEIGHT - STICK_HEIGHT_RUN-170, stickMan, screen, &clipsRight[ frame ] );
                obj.scroll_obst();
                obj.show_obst();
            }
        else if( status == STICK_UP )
            {
                apply_surface( 25, SCREEN_HEIGHT - STICK_HEIGHT_JUMP-180, stickMan, screen, &clipsUp[ frame ] );

                obj.scroll_obst();
                obj.show_obst();
            }
   else if( status == STICK_ROLL )
            {
                apply_surface( 25, SCREEN_HEIGHT - STICK_HEIGHT_RUN-180, stickMan, screen, &clipsR[ frame ] );

                obj.scroll_obst();
                obj.show_obst();
            }

          if(running==true)  {



            //The timer's time as a string
            std::stringstream time;
            std::stringstream score;
            //Convert the timer's time to a string
            time << "Timer: " << (SDL_GetTicks()-start)/1000;
            scr+=(SDL_GetTicks())/4000;
            score<<"Score: " << scr;
            //Render the time surface
            seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor );
            scrs= TTF_RenderText_Solid( font, score.str().c_str(), textColor );
            //Apply the time surface
            apply_surface( 680, 20, seconds, screen );
            apply_surface(  680, 50, scrs, screen );

          }

    }


