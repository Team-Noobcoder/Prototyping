
#include "robot_ResQ.h"


// THIS IS THE FUNCTION YOU IMPLEMENT
// THIS IS THE FUNCTION YOU IMPLEMENT
int move(char* world) {
    int Robot = 0;
    int Target = 0;
    int queue[];
    bool visited[];
    int previous[];
    int direction[4] = { 1,-1,21,-21 };
    int CURRENT_POSITION = ROBOT INDEX;
    int prev[200];
    int t = 0;
int path[];


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


for (int i = 0; i < 200; i++)
{
    visited[i] = 'FALSE'; //if not visited false

}


int c = 0;
int k = 0;
int counter = 1;

queue[0] = CURRENT_POSITION;
// Store coordinate to reach T
for (int y = 0; queue[y] != TARGET_POSITION; y++)
{
    visited[CURRENT_POSITION] == 'TRUE';



    for (int j = 0; j < 4; j++)
    {
        if (queue[CURRENT_POSITION] + direction[j++] < 0 || queue[CURRENT_POSITION] + direction > 200)
        {
            continue;

        }
        else if (world[CURRENT_POSITION + direction] == '#' || world[CURRENT_POSITION + direction] == '*' || visited[CURRENT_POSITION + direction] == 'TRUE';)
        {
            continue;
        }
        else
        {


            queue[counter] = CURRENT_POSITION + direction;
            counter++;
            prev[CURRENT_POSITION + direction] = CURRENT_POSITION;



        }






    }


    CURRENT_POSITION = queue[y];

}

int p = 0;
for (Cl = Target; prev != NULL; )//finding path
{
    path[p] = Cl

        p++;




    Cl = prev[Cl];
}

int r;
int m=0;
for (r = p; r > 0; r--)
{
    repath[m] = path[p];
    p--;
    m++;
}


        
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
    if (difference_H < 0 && (world[Robot - 21] != 'O' || world[Robot - 21] != '~'))
    {
        return 1;

    }

    // Move DOWNWARD
    else if (difference_H > 0 && world[Robot - 21] != '~')
    {

        return 3;
    }

    // Move LEFT
    else if (difference_V < 0 && world[Robot - 21] != '~')
    {
        return 4;

    }

    // Move RIGHT
    else if (difference_V > 0 && world[Robot - 21] != '~')
    {

        return 2;
    }



    Robot = path[t];
    t++

        if (path[t + 1] - Robot == 1)
        {

            return 2;
         }

        else if (path[t + 1] - Robot == -1)
        {

            return 4;

        }  
        else if (path[t + 1] - Robot == 21)
        {

            return 3;

        }


        else if (path[t + 1] - Robot == -21)
        {

            return 1;
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
