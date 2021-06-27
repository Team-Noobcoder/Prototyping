#include "robot_ResQ.h"
#include <stdio.h>
static int queue[200];
static int visited[200];
static int previous[200];
static int current_position;
static int direction[4] = { 1,-1,21,-21 };
static int y;

static int path[200];
static int reversePath[200];
static int p = 0;
static int b = 0;
static int construct;
static int position_target;
static int position_target_water;
static int new_current_position;
static int neighbour;
int Robot;
static int u = 0;
static int forward;
int m;
int z;
static int q = 0;
static int backward;
static int status = 0;
static int mode_a = 0;
static int mode_b = 0;
static int Target;

int current_id = -1;
int c = 0;
int moves_11[] = { 8,3,4,6,1,1,7,2,1,1,2,3,3,8,3,4 };
int moves_12[] = { 4,4,4,4,6,1,5,1,1,3,5,3,3,2,2,2,2 };
int move_counter = 0;



int move(char* world, int map_id)
{
	//Reset
	if (map_id != current_id) {
		c = 0;
		move_counter = 0;
		current_id = map_id;
		backward = 0;
		forward = 0;
		mode_a = 0;
		mode_b = 0;


	}


	switch (status)
	{

	case 0:





		// find R location
		for (Robot = 0; world[Robot] != 'R'; Robot++)
		{

			//printf("%d ", Robot);
			current_position = Robot + 1;

		}
		// find T location


		for (int Target = 0; Target < 200; Target++)
		{
			if (world[Target] == 'T' || world[Target] == 't')

			{

				position_target = Target;
				printf("\n woiii %d", Target);
			}


		}

		printf("Current Position: %d\n", current_position);
		printf("Targett Position:%d\n", position_target);

		queue[0] = current_position;


		for (int v = 0; v < 200; v++) // v for visited)
		{
			visited[v] = 0;

		}

		visited[current_position] = 1;


		for (int prv = 0; prv < 200; prv++) // prv for previous
		{
			previous[prv] = 0;

		}




		// loop to check neighbour and put inside array queue
		int* pointer;
		pointer = &queue[0];


		for (int y = 0; queue[y] != position_target;)

		{
			current_position = *pointer; // pointer to check array neighbor


			//loop to check neighbour for every direction
			for (int d = 0; d < 4; d++) // d for direction

			{
				neighbour = current_position + direction[d];

				if (neighbour < 0 || neighbour > 200)

				{
					continue;

				}


				if (world[neighbour] == 'T' || world[neighbour] == 't')
				{

					queue[neighbour];
					d = 5;
				}


				if (world[neighbour] == '#')
				{
					continue;

				}


				if (visited[neighbour] == 1)

				{

					continue;
				}


				else
				{

					queue[y + 1] = neighbour;
					visited[neighbour] = 1;
					previous[neighbour] = current_position;
					printf("Queue = %d ", queue[y + 1]);
					y++;

				}
			}


			pointer++;

		}

		// to find reverse path
		int find = position_target;

		reversePath[0] = position_target;

		for (int z = 1; find != Robot; z++)
		{
			reversePath[z] = previous[find];
			find = reversePath[z];
			m = z;


		}


		int new = m;

		for (int u = 0; u < m + 1; u++)
		{

			printf("\n Reverse Path  %d ", reversePath[u]);

		}

		//find correct path
		int try = current_position;
		path[m] = current_position;

		for (int k = 0; try != Target; k++)
		{
			path[k] = reversePath[m];
			try = reversePath[m];
			printf("\n Correct Path %d \n ", path[k]);
			m--;


		}

		path[new] = position_target;

		for (int k = 0; k < new + 1; k++)
		{

			if (path[k] == position_target)
			{

				status = 1;


			}


		}



		//mode = 0 (land mode)
	   //mode = 1 (water mode)
	case 1:

		u = forward;

		int north = path[forward] - 21; //upward
		int south = path[forward] + 21; //downward
		int west = path[forward] - 1; // left
		int east = path[forward] + 1; // right


	 //if target in water, ´stay in water mode for reverse path


		if ((path[forward + 1] - path[forward] == -21) && world[north] == 't')
		{

			mode_b = 1;
		}


		if ((path[forward + 1] - path[forward] == 21) && world[south] == 't')
		{

			mode_b = 1;
		}


		if ((path[forward + 1] - path[forward] == 1) && world[east] == 't')
		{

			mode_b = 1;
		}


		if ((path[forward + 1] - path[forward] == -1) && world[west] == 't')
		{

			mode_b = 1;
		}

		//////////////////////////////////////////////

		if (path[forward] == position_target)

		{

		}


		//destroyed south

		else if ((path[forward + 1] - path[forward]) == 21 && world[south] == '*')

		{

			return 8;
		}



		//destroyed north

		else if ((path[forward + 1] - path[forward]) == -21 && world[north] == '*')

		{

			return 6;
		}


		//destroyed west

		else if ((path[forward + 1] - path[forward]) == -1 && world[west] == '*')

		{

			return 9;


		}



		//destroyed east

		else if ((path[forward + 1] - path[forward]) == 1 && world[east] == '*')

		{

			return 7;
		}


		/////////////////////////////
		// change toggling mode then move inside the water (left= ~) 
		else if ((path[forward + 1] - path[forward]) == -1 && world[west] == '~') //water at the left
		{


			if (mode_a == 0 && world[west] == '~')
			{
				mode_a = 1;

				return 5;
			}

			if (mode_a == 1 && world[west] == '~')
			{
				forward++;
				return 4;

			}

		}


		//to change to land mode back (Left is O) 
		else if (((path[forward + 1] - path[forward]) == -1) && (world[west] == 'O' || world[west] == 'T') && (mode_a == 1))
		{



			mode_a = 0;
			return 5;

		}



		/////////////////////////////
		// // change toggling mode then move inside the water (right= ~) 
		else if ((path[forward + 1] - path[forward]) == 1 && world[east] == '~') //water at the right
		{


			if (mode_a == 0 && world[east] == '~')
			{
				mode_a = 1;

				return 5;
			}

			if (mode_a == 1 && world[east] == '~')
			{
				forward++;
				return 2;

			}

		}


		//to change to land mode back (Right is O) 
		else if (((path[forward + 1] - path[forward]) == 1) && (world[east] == 'O' || world[east] == 'T') && (mode_a == 1))
		{



			mode_a = 0;
			return 5;

		}

		///////////////////////////////////////////
		/////////////////////////////
		//  change toggling mode then move inside the water (upward= ~) 
		else if ((path[forward + 1] - path[forward]) == -21 && world[north] == '~') //water at the top
		{


			if (mode_a == 0 && world[north] == '~')
			{
				mode_a = 1;

				return 5;
			}

			if (mode_a == 1 && world[north] == '~')
			{
				forward++;
				return 1;

			}

		}


		//to change to land mode back (Top is O)
		else if (((path[forward + 1] - path[forward]) == -21) && (world[north] == 'O' || world[north] == 'T') && (mode_a == 1))
		{



			mode_a = 0;
			return 5;

		}

		///////////////////////////////////////////

		 /////////////////////////////
		//  change toggling mode then move inside the water (downward= ~) 
		else if ((path[forward + 1] - path[forward]) == 21 && world[south] == '~') //water at the below
		{


			if (mode_a == 0 && world[south] == '~')
			{
				mode_a = 1;

				return 5;
			}





			if (mode_a == 1 && world[south] == '~')
			{
				forward++;
				return 3;

			}

		}


		//to change to land mode back (Down is O)
		else if (((path[forward + 1] - path[forward]) == 21) && (world[south] == 'O' || world[south] == 'T') && (mode_a == 1))
		{


			mode_a = 0;
			return 5;

		}

		///////////////////////////////////////////

		//Movement when no Water
		//Move to west when no Water 
		else if ((path[forward + 1] - path[forward]) == -1 && world[west] != '~')
		{


			forward++;
			return 4;
		}
		//Move to east when no Water
		else if ((path[forward + 1] - path[forward]) == 1 && world[east] != '~')
		{

			forward++;
			return 2;
		}
		//Move to North when no Water
		else if ((path[forward + 1] - path[forward]) == -21 && world[north] != '~')
		{


			forward++;
			return 1;
		}

		//Move to South when no Water
		else if ((path[forward + 1] - path[forward]) == 21 && world[south] != '~')
		{


			forward++;
			return 3;
		}

	case 2:

		q = backward;
		printf("\n kimi harini %d", mode_a);



		printf("\n bedd harini %d", mode_b);
		int Rnorth = reversePath[backward] - 21; //North when return
		int Rsouth = reversePath[backward] + 21; //South when return
		int Rwest = reversePath[backward] - 1; // West when return
		int Reast = reversePath[backward] + 1; // East when return

		if (reversePath[backward + 1] == Robot)
		{
			status = 0;

		}


		if (reversePath[backward] == Robot)
		{

		}


		/////////////////////////////
		// change toggling mode then move inside the water (left= ~)

		else if ((reversePath[backward + 1] - reversePath[backward]) == -1 && world[Rwest] == '~')  //water at the left
		{


			if (mode_b == 0 && world[Rwest] == '~')
			{
				mode_b = 1;

				return 5;
			}

			if (mode_b == 1 && world[Rwest] == '~')
			{
				backward++;
				return 4;

			}

		}


		//to change to land mode back (Left is O) 
		else if (((reversePath[backward + 1] - reversePath[backward]) == -1) && (world[Rwest] == 'O') && (mode_b == 1))
		{
			printf("masuk tak weh");


			mode_b = 0;
			return 5;

		}

		/////////////////////////////
		// change toggling mode then move inside the water (right= ~) 
		else if ((reversePath[backward + 1] - reversePath[backward]) == 1 && world[Reast] == '~') //water at the right
		{


			if (mode_b == 0 && world[Reast] == '~')
			{
				mode_b = 1;

				return 5;
			}

			if (mode_b == 1 && world[Reast] == '~')
			{
				backward++;
				return 2;

			}

		}

		//to change to land mode back (Right is O) 
		else if ((reversePath[backward + 1] - reversePath[backward] == 1) && (world[Reast] == 'O') && (mode_b == 1))
		{
			printf("masuk tak weh");


			mode_b = 0;
			return 5;

		}

		///////////////////////////////////////////
		/////////////////////////////
	//  change toggling mode then move inside the water (upward= ~) 
		else if ((reversePath[backward + 1] - reversePath[backward]) == -21 && world[Rnorth] == '~') //water at the top
		{


			if (mode_b == 0 && world[Rnorth] == '~')
			{
				mode_b = 1;

				return 5;
			}

			if (mode_b == 1 && world[Rnorth] == '~')
			{
				backward++;
				return 1;

			}

		}

		//to change to land mode back (Top is O)
		else if (((reversePath[backward + 1] - reversePath[backward]) == -21) && (world[Rnorth] == 'O') && (mode_b == 1))
		{
			printf("masuk tak weh");


			mode_b = 0;
			return 5;

		}

		///////////////////////////////////////////


		/////////////////////////////
		//  change toggling mode then move inside the water (downward= ~) 
		else if ((reversePath[backward + 1] - reversePath[backward]) == 21 && world[Rsouth] == '~') //water at the below
		{


			if (mode_b == 0 && world[Rsouth] == '~')
			{
				mode_b = 1;
				printf("lalalal %d", mode_b);
				return 5;
			}

			if (mode_b == 1 && world[Rsouth] == '~')
			{
				backward++;
				return 3;

			}

		}


		//to change to land mode back (Down is O)
		else if ((reversePath[backward + 1] - reversePath[backward]) == 21 && (world[Rsouth] == 'O') && (mode_b == 1))
		{
			printf("masuk tak weh");


			mode_b = 0;
			return 5;

		}

		///////////////////////////////////////////

		//Movement when no Water
		else if ((reversePath[backward + 1] - reversePath[backward]) == -1 && world[Rwest] != '~')
		{
			backward++;
			return 4;
		}

		else if ((reversePath[backward + 1] - reversePath[backward]) == 1 && world[Reast] != '~')
		{

			backward++;
			return 2;
		}



		else if ((reversePath[backward + 1] - reversePath[backward]) == -21 && world[Rnorth] != '~')
		{
			backward++;
			return 1;
		}



		else if ((reversePath[backward + 1] - reversePath[backward]) == 21 && world[Rsouth] != '~')
		{

			backward++;
			return 3;
		}

	}

}














