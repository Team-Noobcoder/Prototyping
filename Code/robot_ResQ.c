
#include "ResQbot.h"


// THIS IS THE FUNCTION YOU IMPLEMENT
// THIS IS THE FUNCTION YOU IMPLEMENT
int move(char* world) {
    int Robot = 0;
    int Target = 0;

    for (Robot = 0; world[Robot] != 'R'; Robot++)
    {

    }
    for (Target = 0; world[Target] != 'T'; Target++)
    {

    }

    int Horizontal_T;
    Horizontal_T = Target / 21;

    int Horizontal_R;
    Horizontal_R = Robot / 21;

    int difference_H = Horizontal_T - Horizontal_R;//Column difference

    int Vertical_T = Target % 21;
    int Vertical_R = Robot % 21;

    int difference_V = Vertical_T - Vertical_R;//Row difference
     
    // To change status water or land mode
    if (status == 0 && world[Robot - 21] == '~')
    {
        status = 1;
        return 5;
    }

    if (status == 1 && world[Robot - 21] == '~')
    {
        return 1;

    }


    if (status == 1 && world[Robot - 21] == 'O')
    {
        status = 0;
        return 5;

    }  

    // Move UPWARD
    if (difference_H < 0  && (world[Robot-21]!='O' || world[Robot - 21] != '~'))
    {
        return 1;

    }

    // Move DOWNWARD
    else if (difference_H > 0 && world[Robot - 21] != '~')
    {

        return 3;
    }

    // Move LEFT
    else if (difference_V < 0  && world[Robot - 21] != '~')
    {
        return 4;

    }

    // Move RIGHT
    else if (difference_V > 0 && world[Robot - 21] != '~')
    {

        return 2;
    }

















    /*
    // Moving when there is wall in centre map
    if (different_H == 0)
    {

        status_Vertical = 1;







    }



    if (different_H < 0 && world[Robot + 1] == '#' && world[Robot - 21] == '#')//wall up and right
    {

        return 4;
    }


    if (different_H < 0 && world[Robot + 1] == '#' && world[Robot - 1] == '#' && world[Robot - 21] != '#')//wall left and right
    {

        return 1;
    }
     
    if (different_H < 0 && world[Robot - 21] == '#')//wall up
    {

        return 4;
    }




    
    if (status == 0 && world[Robot - 21] == '~')
    {
        status = 1;
            return 5;
    }

    if (status == 1 && world[Robot - 21] == '~')
    {
        return 1;

    }


    if (status == 1 && world[Robot - 21] == 'O')
    {
        status = 0;
        return 5;

    }


    if (status == 0 && world[Robot - 21] == 'O')
    {
       
        return 1;

    }
   */


}
