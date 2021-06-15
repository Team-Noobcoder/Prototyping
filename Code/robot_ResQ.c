
#include "robot_ResQ.h"


// THIS IS THE FUNCTION YOU IMPLEMENT
// THIS IS THE FUNCTION YOU IMPLEMENT
int move(char* world) {
    int Robot = 0;
    int Target = 0;
    bool visited[200];
    int queue[];
    int direction[4] = { 1,-1,21,-21 };
    int previous[];
    int current_position;
    int path[];
    int repath[];
    int b = 0;


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
    visted[i] = 'FALSE';


}



current_position = R;

queue[0] = current_position;
int y = 0;
int counter = 1;
int p = 0;

for (y=0; queue[y]!= Target; y++)

{ 

    current_position = queue[y];
    visited[current_position] = 'TRUE';


    for (int d = 0; d < 4; d++)
    {

        if (queue[current_position] + direction[d] < 0 || queue[current_position] + direction[d] Y > 200)
        {
            

        }
        else if (world[current_position] + direction[d] == '#' || world[current_position] + direction[d] == '*' || world[current_position] + direction[d] == '~')
        {

           
        }
        else if(visited[current_position]=='TRUE')


       

        else

        {
            queue[counter] = current_position + direction[d];
            prev[current_position + direction] = current_position;



            counter++;
             
        }


  

    }







}

      int p = 0;

      for (construct = Target; prev[construct] != 'NULL') //reconstruct path

     { 
          

          path[p]=construct;
          p++;
          
         construct=prev[construct];

     }



      int r = p;
      int m = 0;
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



    Robot = repath[b];
    b++;
     

    if (repath[b + 1] - Robot == 1)
    {

        return 2;
    }



      else if (repath[b + 1] - Robot == -1)
    {

        return 4;
    }



      else if (repath[b + 1] - Robot == 21)
    {
        return 3;

    }


      else if (repath[b + 1] - Robot == -21)
    {

        return 4;
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
