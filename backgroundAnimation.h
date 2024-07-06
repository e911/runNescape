class backgr
{
private:
    int bgX;
    int bgY;

public:
    backgr();
    void scroll_backgr();
    void show_backgr();
};

    backgr::backgr()
    {
    //The offsets of the background
 bgX = 0, bgY = 0;

    }
    void backgr::scroll_backgr()
    {
            //Scroll background
        bgX -= 2;

        //If the background has gone too far
        if( bgX <= -background->w )
        {
            //Reset the offset
            bgX = 0;
        }
    }

      void backgr::show_backgr()
       {
       //Show the background
        apply_surface( bgX, bgY, background, screen );
        apply_surface( bgX + background->w, bgY, background, screen );
         apply_surface(bgX,bgY,background,screen);
       }


