
#include "robot_ResQ.h"

static int queue[200];
static int visited[200];
static int previous[200];
static int current_position;
static int direction[4] = { 1,-1,21,-21 };
static int y = 1;
static int c = 0;
static int path[200];
static int repath[200];
static int p = 0;
static int b = 0;
static int construct;



int move(char* world)
{
	// find R location
	for (Robot = 0; world[Robot] != 'R'; Robot++)
	{

	}
	// find T location
	for (Target = 0; world[Target] != 'T'; Target++)
	{

	}



	Robot = current_position;
	queue[0] = current_position;

	for (int v = 0; v < 200; v++) // v for visited)
	{
		visited[v] = 0;

	}

	visited[current_position] = 1;







	// loop to check neighbour and inside array queue

	int y = 1;
	while (queue[y] != Target)

	{

		//queue[c] = current_position; // c for counter to check array neighbour
		current_position = queue[c];
		for (int d = 0; d < 4; d++) // d for direction

		{
			if (world[current_position + direction[d]] == '#' || world[current_position + direction[d]] == '~' || world[current_position + direction[d]] == '*')
			{


			}

			else if (visited[current_position] == 1)

			{


			}
			else if (world[current_position + direction[d]] == 'T')
			{

				queue[y] = current_position + direction[d];
				d = 5;
				y++;
				visited[current_position + direction[d]] = 1;
				previous[current_position + direction[d]] = current_position;
			}


			else
			{
				//current_position + direction[d] = queue[y];

				queue[y] = current_position + direction[d];
				y++;
				visited[current_position + direction[d]] = 1;
				previous[current_position + direction[d]] = current_position;

			}
		}


		c++;

	}


	// construct path from target to robot

	for (construct = Target; previous[construct] != 'NULL'; construct = previous[Target])
	{

		path[p] = construct;
		p++;

	}

	int r = p;
	int m = 0;
	// construct path from r to t
	for (r = p; r > 0; r--)
	{

		repath[m] = path[p];
		p--;
		m++;
	}



	// to move 
	Robot = repath[b];
	b++;

	//east
	if (repath[b + 1] - Robot == 1)
	{

		return 2;
	}


	//west
	else if (repath[b + 1] - Robot == -1)
	{

		return 4;
	}


	//south
	else if (repath[b + 1] - Robot == 21)
	{
		return 3;

	}

	//north
	else if (repath[b + 1] - Robot == -21)
	{

		return 4;
	}


}
