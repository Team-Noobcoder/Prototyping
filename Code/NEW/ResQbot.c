
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

    if (difference_V < -2)
    {
        return 4;

    }
    if ((world[Robot + 1] == '#' || world[Robot + 1] == 'O') && world[Robot - 21] == '#')
    {
        return 4;
    }



    else if (difference_H > 0)
    {

        return 3;
    }
    else if (difference_H < 0 && world[Robot - 21] != '#')
    {
        return 1;

    }
    else if (difference_V > 0)
    {

        return 2;
    }

}