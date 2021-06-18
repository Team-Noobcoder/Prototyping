#include "robot_ResQ.h"

static int queue[200];
static int visited[200];
static int previous[200];
static int current_position;
static int direction[4] = { 1,-1,21,-21 };
static int y;
static int c;
static int path[200];
static int repath[200];
static int p = 0;
static int b = 0;
static int construct;
static int position_target;
static int new_current_position;


int move(char* world)
{
	// find R location
	for (Robot = 0; world[Robot] != 'R'; Robot++)
	{
		current_position = Robot;

	}
	// find T location
	for (Target = 0; world[Target] != 'T'; Target++)
	{
		position_target = Target;


	}


	printf("%d\n", current_position);
	printf("%d\n", position_target);

	queue[0] = current_position;
	printf("%d\n", queue[0]);


	for (int v = 0; v < 200; v++) // v for visited)
	{
		visited[v] = 0;

	}

	visited[current_position] = 1;


	for (int prv = 0; prv < 200; prv++) // prv for previous
	{
		previous[prv] = 0;

	}




	// loop to check neighbour and inside array queue



	int* pointer;
	pointer = &queue[0];
	c = 0;

	for (int y = 0; queue[y] != position_target; c++)

	{
		current_position = *pointer;

		//queue[c] = current_position; // c for counter to check array neighbour
		  //current_position = queue[c] ;

		for (int d = 0; d < 4; d++) // d for direction

		{
			if (world[current_position + direction[d]] == '#' || world[current_position + direction[d]] == '~' || world[current_position + direction[d]] == '*')
			{


			}

			else if (world[current_position + direction[d]] < 0 || world[current_position + direction[d]]>200)

			{


			}



			else if (visited[current_position + direction[d]] == 1)

			{


			}

			else if (world[current_position + direction[d]] == 'T')
			{

				queue[y + 1] = current_position + direction[d];


				visited[current_position + direction[d]] = 1;
				previous[current_position + direction[d]] = current_position;
				//current_position = current_position + direction[d];
				y++;
				break;
			}


			else
			{
				//current_position + direction[d] = queue[y];

				queue[y + 1] = current_position + direction[d];

				visited[current_position + direction[d]] = 1;
				previous[current_position + direction[d]] = current_position;
				//current_position = current_position + direction[d];
				printf("%d ", queue[y + 1]);
				y++;


			}
		}


		pointer++;

	}


	// construct path from target to robot

	for (construct = position_target; previous[construct] != 0; construct = previous[position_target])
	{

		path[p] = construct;
		p++;
		printf("%d", path[p]);
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
