#include "Exam.h"

void Place_enemy_fleet()
{
	srand(time(NULL));
	Place_enemy_ship_4();
	Enemy_correction();
	place_flag = 0;
	while (place_flag == 0)
		Place_enemy_ship_3();
	Enemy_correction();
	place_flag = 0;
	while (place_flag == 0)
		Place_enemy_ship_3();
	Enemy_correction();
	for (int i = 0; i < 4; i++)
	{
		place_flag = 0;
		while (place_flag == 0)
			Place_enemy_ship_2();
		Enemy_correction();
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (enemy_fleet[i][j] == 2)
				enemy_fleet[i][j] = 0;
}

void Place_enemy_ship_4()
{
	int height, width, rand_dir;
	height = rand() % 6 + 2;
	width = rand() % 6 + 2;
	rand_dir = rand() % 3;
	switch (rand_dir)
	{
	case 0:
		enemy_fleet[height][width] = 1;
		enemy_fleet[height - 1][width] = 1;
		enemy_fleet[height - 2][width] = 1;
		enemy_fleet[height + 1][width] = 1;
		break;
	case 1:
		enemy_fleet[height][width] = 1;
		enemy_fleet[height][width + 1] = 1;
		enemy_fleet[height][width + 2] = 1;
		enemy_fleet[height][width - 1] = 1;
		break;
	case 2:
		enemy_fleet[height][width] = 1;
		enemy_fleet[height + 1][width] = 1;
		enemy_fleet[height + 2][width] = 1;
		enemy_fleet[height - 1][width] = 1;
		break;
	case 3:
		enemy_fleet[height][width] = 1;
		enemy_fleet[height][width - 1] = 1;
		enemy_fleet[height][width - 2] = 1;
		enemy_fleet[height][width + 1] = 1;
		break;
	}
}

void Place_enemy_ship_3()
{
	int height, width, rand_dir;
	height = rand() % 8 + 1;
	width = rand() % 8 + 1;
	rand_dir = rand() % 2;
	switch (rand_dir)
	{
	case 0:
		if ((enemy_fleet[height][width] == 0)
			&& (enemy_fleet[height - 1][width] == 0)
			&& (enemy_fleet[height + 1][width] == 0)
			&& (height - 1 >= 0) && (height + 1 < 10))
		{
			enemy_fleet[height][width] = 1;
			enemy_fleet[height - 1][width] = 1;
			enemy_fleet[height + 1][width] = 1;
			place_flag = 1;
			break;
		}
	case 1:
		if ((enemy_fleet[height][width] == 0)
			&& (enemy_fleet[height][width + 1] == 0)
			&& (enemy_fleet[height][width - 1] == 0)
			&& (width - 1 >= 0) && (width + 1 < 10))
		{
			enemy_fleet[height][width] = 1;
			enemy_fleet[height][width + 1] = 1;
			enemy_fleet[height][width - 1] = 1;
			place_flag = 1;
			break;
		}
	}
}

void Place_enemy_ship_2()
{
	int height, width, rand_dir;
	height = rand() % 10;
	width = rand() % 10;
	rand_dir = rand() % 4;
	switch (rand_dir)
	case 0:
	{
		if ((enemy_fleet[height][width] == 0)
			&& (enemy_fleet[height - 1][width] == 0)
			&& (height - 1 >= 0))
		{
			enemy_fleet[height][width] = 1;
			enemy_fleet[height - 1][width] = 1;
			place_flag = 1;
			break;
		}
	case 1:
		if ((enemy_fleet[height][width] == 0)
			&& (enemy_fleet[height][width + 1] == 0)
			&& (width + 1 < 10))
		{
			enemy_fleet[height][width] = 1;
			enemy_fleet[height][width + 1] = 1;
			place_flag = 1;
			break;
		}
	case 2:
		if ((enemy_fleet[height][width] == 0)
			&& (enemy_fleet[height + 1][width] == 0)
			&& (height + 1 < 10))
		{
			enemy_fleet[height][width] = 1;
			enemy_fleet[height + 1][width] = 1;
			place_flag = 1;
			break;
		}
	case 3:
		if ((enemy_fleet[height][width] == 0)
			&& (enemy_fleet[height][width - 1] == 0)
			&& (width - 1 >= 0))
		{
			enemy_fleet[height][width] = 1;
			enemy_fleet[height][width - 1] = 1;
			place_flag = 1;
			break;
		}
	}
}

void Enemy_correction()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (enemy_fleet[i][j] == 1)
			{
				if ((i - 1 >= 0) && (j - 1 >= 0) && (enemy_fleet[i - 1][j - 1] != 1))
					enemy_fleet[i - 1][j - 1] = 2;
				if ((i - 1 >= 0) && (enemy_fleet[i - 1][j] != 1))
					enemy_fleet[i - 1][j] = 2;
				if ((i - 1 >= 0) && (j + 1 < 10) && (enemy_fleet[i - 1][j + 1] != 1))
					enemy_fleet[i - 1][j + 1] = 2;
				if ((j - 1 >= 0) && (enemy_fleet[i][j - 1] != 1))
					enemy_fleet[i][j - 1] = 2;
				if ((j + 1 < 10) && (enemy_fleet[i][j + 1] != 1))
					enemy_fleet[i][j + 1] = 2;
				if ((i + 1 < 10) && (j - 1 >= 0) && (enemy_fleet[i + 1][j - 1] != 1))
					enemy_fleet[i + 1][j - 1] = 2;
				if ((i + 1 < 10) && (enemy_fleet[i + 1][j] != 1))
					enemy_fleet[i + 1][j] = 2;
				if ((i + 1 < 10) && (j + 1 < 10) && (enemy_fleet[i + 1][j + 1] != 1))
					enemy_fleet[i + 1][j + 1] = 2;
			}
}