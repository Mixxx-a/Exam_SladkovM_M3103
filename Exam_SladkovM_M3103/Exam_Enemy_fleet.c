#include "Exam.h"

void Place_enemy_fleet()
{
	srand(time(NULL));
	Place_enemy_ship(4);
	Enemy_correction();
	place_flag = not_placed;
	while (place_flag == not_placed)
		Place_enemy_ship(3);
	Enemy_correction();
	place_flag = not_placed;
	while (place_flag == not_placed)
		Place_enemy_ship(3);
	Enemy_correction();
	for (int i = 0; i < 4; i++)
	{
		place_flag = not_placed;
		while (place_flag == not_placed)
			Place_enemy_ship(2);
		Enemy_correction();
	}
	for (int i = 0; i < bat_length; i++)
		for (int j = 0; j < bat_length; j++)
			if (enemy_fleet[i][j] == cell_nothing)
				enemy_fleet[i][j] = cell_empty;
}

void Place_enemy_ship(int decks) /* ??????????????????????????????????????????? */
{
	int height, width, rand_dir;
	switch (decks)
	{
	case 4:
		height = rand() % 6 + 2;
		width = rand() % 6 + 2;
		rand_dir = rand() % 4;
		switch (rand_dir)
		{
		case dir_up:
			enemy_fleet[height][width] = cell_ship;
			enemy_fleet[height - 1][width] = cell_ship;
			enemy_fleet[height - 2][width] = cell_ship;
			enemy_fleet[height + 1][width] = cell_ship;
			break;
		case dir_right:
			enemy_fleet[height][width] = cell_ship;
			enemy_fleet[height][width + 1] = cell_ship;
			enemy_fleet[height][width + 2] = cell_ship;
			enemy_fleet[height][width - 1] = cell_ship;
			break;
		case dir_down:
			enemy_fleet[height][width] = cell_ship;
			enemy_fleet[height + 1][width] = cell_ship;
			enemy_fleet[height + 2][width] = cell_ship;
			enemy_fleet[height - 1][width] = cell_ship;
			break;
		case dir_left:
			enemy_fleet[height][width] = cell_ship;
			enemy_fleet[height][width - 1] = cell_ship;
			enemy_fleet[height][width - 2] = cell_ship;
			enemy_fleet[height][width + 1] = cell_ship;
			break;
		}
		break;

	case 3:
		height = rand() % 8 + 1;
		width = rand() % 8 + 1;
		rand_dir = rand() % 2;
		switch (rand_dir)
		{
		case 0:
			if ((enemy_fleet[height][width] == cell_empty)
				&& (enemy_fleet[height - 1][width] == cell_empty)
				&& (enemy_fleet[height + 1][width] == cell_empty)
				&& (height - 1 >= 0) && (height + 1 < bat_length))
			{
				enemy_fleet[height][width] = cell_ship;
				enemy_fleet[height - 1][width] = cell_ship;
				enemy_fleet[height + 1][width] = cell_ship;
				place_flag = placed;
			}
			break;
		case 1:
			if ((enemy_fleet[height][width] == cell_empty)
				&& (enemy_fleet[height][width + 1] == cell_empty)
				&& (enemy_fleet[height][width - 1] == cell_empty)
				&& (width - 1 >= 0) && (width + 1 < bat_length))
			{
				enemy_fleet[height][width] = cell_ship;
				enemy_fleet[height][width + 1] = cell_ship;
				enemy_fleet[height][width - 1] = cell_ship;
				place_flag = placed;
			}
			break;
		}
		break;

	case 2:
		height = rand() % bat_length;
		width = rand() % bat_length;
		rand_dir = rand() % 4;
		switch (rand_dir)
		case dir_up:
		{
			if ((enemy_fleet[height][width] == cell_empty)
				&& (enemy_fleet[height - 1][width] == cell_empty)
				&& (height - 1 >= 0))
			{
				enemy_fleet[height][width] = cell_ship;
				enemy_fleet[height - 1][width] = cell_ship;
				place_flag = placed;
			}
			break;
		case dir_right:
			if ((enemy_fleet[height][width] == cell_empty)
				&& (enemy_fleet[height][width + 1] == cell_empty)
				&& (width + 1 < bat_length))
			{
				enemy_fleet[height][width] = cell_ship;
				enemy_fleet[height][width + 1] = cell_ship;
				place_flag = placed;
			}
			break;
		case dir_down:
			if ((enemy_fleet[height][width] == cell_empty)
				&& (enemy_fleet[height + 1][width] == cell_empty)
				&& (height + 1 < bat_length))
			{
				enemy_fleet[height][width] = cell_ship;
				enemy_fleet[height + 1][width] = cell_ship;
				place_flag = placed;
			}
			break;
		case dir_left:
			if ((enemy_fleet[height][width] == cell_empty)
				&& (enemy_fleet[height][width - 1] == cell_empty)
				&& (width - 1 >= 0))
			{
				enemy_fleet[height][width] = cell_ship;
				enemy_fleet[height][width - 1] = cell_ship;
				place_flag = placed;
			}
			break;
		}
		break;
	}
}

void Enemy_correction()
{
	for (int i = 0; i < bat_length; i++)
		for (int j = 0; j < bat_length; j++)
			if (enemy_fleet[i][j] == cell_ship)
			{
				if ((i - 1 >= 0) && (j - 1 >= 0))
					enemy_fleet[i - 1][j - 1] = cell_nothing;
				if ((i - 1 >= 0) && (enemy_fleet[i - 1][j] != cell_ship))
					enemy_fleet[i - 1][j] = cell_nothing;
				if ((i - 1 >= 0) && (j + 1 < bat_length))
					enemy_fleet[i - 1][j + 1] = cell_nothing;
				if ((j - 1 >= 0) && (enemy_fleet[i][j - 1] != cell_ship))
					enemy_fleet[i][j - 1] = cell_nothing;
				if ((j + 1 < bat_length) && (enemy_fleet[i][j + 1] != cell_ship))
					enemy_fleet[i][j + 1] = cell_nothing;
				if ((i + 1 < bat_length) && (j - 1 >= 0))
					enemy_fleet[i + 1][j - 1] = cell_nothing;
				if ((i + 1 < bat_length) && (enemy_fleet[i + 1][j] != cell_ship))
					enemy_fleet[i + 1][j] = cell_nothing;
				if ((i + 1 < bat_length) && (j + 1 < bat_length))
					enemy_fleet[i + 1][j + 1] = cell_nothing;
			}
}