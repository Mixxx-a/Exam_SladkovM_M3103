#include "Exam.h"

int Enemy_turn_t1()
{
	int h = rand() % bat_length, w = rand() % bat_length;
	while ((my_fleet[h][w] == cell_nothing) || (my_fleet[h][w] == cell_destroyed))
	{
		h = rand() % bat_length;
		w = rand() % bat_length;
	}
	printf("\n Enemy shooting %c%d \n", Number_symbol(h + 1), w + 1);
	if (my_fleet[h][w] == cell_ship)
	{
		my_fleet[h][w] = cell_destroyed;
		my_counter--;
		if (my_counter == 0)
			return 0;
		printf("He hits and shoots again! \n");
		Enemy_turn_t1();
	}
	else
	{
		my_fleet[h][w] = cell_nothing;
		printf("He missed. Your turn. \n");
		return 1;
	}
}

int Enemy_turn_t2(int h, int w)
{
	if ((h == -1) && (w == -1))
	{
		h = rand() % bat_length;
		w = rand() % bat_length;
		while ((my_fleet[h][w] == cell_nothing) || (my_fleet[h][w] == cell_destroyed))
		{
			h = rand() % bat_length;
			w = rand() % bat_length;
		}
	}
	if (my_fleet[h][w] == cell_ship)
	{
		printf("\n Enemy shooting %c%d \n", Number_symbol(h + 1), w + 1);
		my_counter--;
		my_fleet[h][w] = cell_destroyed;
		if (my_counter == 0)
			return 0;
		if (enemy_num_cells == 0)
		{
			enemy_num_cells = My_check_destroy(h, w);
			if (enemy_num_cells == 2)
			{
				h_started = h;
				w_started = w;
			}
			printf("He hits and shoots again! \n");
			Shooting(h, w);
		}
		else
		{
			enemy_num_cells = enemy_num_cells - 1 + My_check_destroy(h, w);
			if (enemy_num_cells == 0)
			{
				printf("Bot destroyed your ship! He shoots again");
				Shooting_correction();
				for (int i = 0; i < 3; i++)
					dir_history[i] = -1;
				dir_history_counter = 0;
				previous_shoot = 0;
				Enemy_turn_t2(-1, -1);
			}
			else
			{
				printf("He hits and shoots again! \n");
				previous_shoot = 1;
				if (My_check_destroy(h, w) == 0)
					Shooting(h_started, w_started);
				else
					Shooting(h, w);
			}
		}
	}
	else if (my_fleet[h][w] == cell_destroyed)
	{
		Shooting(h, w);
	}
	else
	{
		printf("\n Enemy shooting %c%d \n", Number_symbol(h + 1), w + 1);
		my_fleet[h][w] = cell_nothing;
		printf("He missed. Your turn. \n");
		if (previous_shoot == 1)
		{
			if ((dir_turn == dir_down) || (dir_turn == dir_left))
				dir_turn -= 2;
			else if ((dir_turn == dir_up) || (dir_turn == dir_right))
				dir_turn += 2;
		}
		else
			dir_turn = dir_nothing;
		if (enemy_num_cells == 0)
		{
			h_old = -1;
			w_old = -1;
			dir_turn = dir_nothing;
		}
		return 1;
	}
}

void Shooting(int h, int w)
{
	int dir_correction = 0;
	h_old = h;
	w_old = w;
	if (dir_turn == dir_nothing)
	{
		while (dir_correction != 3)
		{
			dir_correction = 0;
			dir_turn = rand() % 4;
			for (int i = 0; i < 3; i++)
				if (dir_turn == dir_history[i])
					break;
				else
					dir_correction++;
		}
	}
	switch (dir_turn)
	{
	case dir_up:
		if (h - 1 >= 0)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h - 1, w);
		}
		else
		{
			dir_turn = dir_down;
			Shooting(h, w);
		}
		break;
	case dir_right:
		if (w + 1 < bat_length)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h, w + 1);
		}
		else
		{
			dir_turn = dir_left;
			Shooting(h, w);
		}
		break;
	case dir_down:
		if (h + 1 < bat_length)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h + 1, w);
		}
		else
		{
			dir_turn = dir_up;
			Shooting(h, w);
		}
		break;
	case dir_left:
		if (w - 1 >= 0)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h, w - 1);
		}
		else
		{
			dir_turn = dir_right;
			Shooting(h, w);
		}
		break;
	}
}


int My_check_destroy(int i, int j)
{
	int count = 0;
	if (my_fleet[i - 1][j] == cell_ship)
		count++;
	if (my_fleet[i][j - 1] == cell_ship)
		count++;
	if (my_fleet[i][j + 1] == cell_ship)
		count++;
	if (my_fleet[i + 1][j] == cell_ship)
		count++;;
	return count;
}

void Shooting_correction()
{
	for (int i = 0; i < bat_length; i++)
		for (int j = 0; j < bat_length; j++)
			if (my_fleet[i][j] == cell_destroyed)
			{
				if ((i - 1 >= 0) && (j - 1 >= 0))
					my_fleet[i - 1][j - 1] = cell_nothing;
				if ((i - 1 >= 0) && (my_fleet[i - 1][j] != cell_destroyed))
					my_fleet[i - 1][j] = cell_nothing;
				if ((i - 1 >= 0) && (j + 1 < bat_length))
					my_fleet[i - 1][j + 1] = cell_nothing;
				if ((j - 1 >= 0) && (my_fleet[i][j - 1] != cell_destroyed))
					my_fleet[i][j - 1] = cell_nothing;
				if ((j + 1 < bat_length) && (my_fleet[i][j + 1] != cell_destroyed))
					my_fleet[i][j + 1] = cell_nothing;
				if ((i + 1 < bat_length) && (j - 1 >= 0))
					my_fleet[i + 1][j - 1] = cell_nothing;
				if ((i + 1 < bat_length) && (my_fleet[i + 1][j] != cell_destroyed))
					my_fleet[i + 1][j] = cell_nothing;
				if ((i + 1 < bat_length) && (j + 1 < bat_length))
					my_fleet[i + 1][j + 1] = cell_nothing;
			}
}