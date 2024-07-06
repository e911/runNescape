#include <time.h>


class obstacle
    {
        private:
            int bgx, bgx1;
            int bgy, bgy1;

        public:
            obstacle();
            void scroll_obst();
            void show_obst();
    };


obstacle::obstacle()
    {
        //The offsets of the background
        srand(time(NULL));
        box.x =  rand() % 100+550;
        box.y= 170+ rand()%100;
         box1.x=  rand() % 100+650;
        box1.y= 170+ rand()%100;
        box.w=40;
 box.h=40;
    }

void obstacle::scroll_obst()
    {
        //Scroll obstacle
         box.x -= 30;
        box1.x-=30;

            //If the obstacle has gone too far
        if(  box.x <= -obst->w )
            {            //Reset the offset
                srand(time(NULL));
                 box.x = rand() % 200+740;
                box.y = 210+ rand()%90;
            }
        if( box1.x <= -obst2->w)
            {
                srand(time(NULL));
                 box1.x = rand() % 200+840;
                box1.y = 210+ rand()%90;
            }
    }

void obstacle::show_obst()
    {
        //Show the obstacle
        apply_surface(  box.x + obst->w,  box.y, obst, screen );
        apply_surface(  box1.x + obst2->w, box1.y, obst2, screen );
    }

