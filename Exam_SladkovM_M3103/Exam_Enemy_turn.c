#include "Exam.h"

int Enemy_turn_t1()
{
	int h = rand() % 10, w = rand() % 10;
	while ((my_fleet[h][w] == 2) || (my_fleet[h][w] == 3))
	{
		h = rand() % 10;
		w = rand() % 10;
	}
	printf("\n Enemy shooting %c%d \n", Number_symbol(h + 1), w + 1);
	if (my_fleet[h][w] == 1)
	{
		my_fleet[h][w] = 3;
		my_counter--;
		if (my_counter == 0)
			return 0;
		printf("He hits and shoots again! \n");
		Enemy_turn_t1();
	}
	else
	{
		my_fleet[h][w] = 2;
		printf("He missed. Your turn. \n");
		return 1;
	}
}

int Enemy_turn_t2(int h, int w)
{
	if ((h == -1) && (w == -1))
	{
		h = rand() % 10;
		w = rand() % 10;
		while ((my_fleet[h][w] == 2) || (my_fleet[h][w] == 3))
		{
			h = rand() % 10;
			w = rand() % 10;
		}
	}
	if (my_fleet[h][w] == 1)
	{
		printf("\n Enemy shooting %c%d \n", Number_symbol(h + 1), w + 1);
		my_counter--;
		my_fleet[h][w] = 3;
		if (my_counter == 0)
			return 0;
		if (enemy_num_cells == 0)
		{
			enemy_num_cells = My_check_destroy(Symbol_number(h), w);
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
	else if (my_fleet[h][w] == 3)
	{
		Shooting(h, w);
	}
	else
	{
		printf("\n Enemy shooting %c%d \n", Number_symbol(h + 1), w + 1);
		my_fleet[h][w] = 2;
		printf("He missed. Your turn. \n");
		if (previous_shoot == 1)
		{
			if ((dir_turn == 2) || (dir_turn == 3))
				dir_turn -= 2;
			else if ((dir_turn == 0) || (dir_turn == 1))
				dir_turn += 2;
		}
		else
			dir_turn = -1;
		if (enemy_num_cells == 0)
		{
			h_old = -1;
			w_old = -1;
			dir_turn = -1;
		}
		return 1;
	}
}

void Shooting(int h, int w)
{
	int dir_correction = 0;
	h_old = h;
	w_old = w;
	if (dir_turn == -1)
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
	case 0:
		if (h - 1 >= 0)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h - 1, w);
		}
		else
		{
			dir_turn = 2;
			Shooting(h, w);
		}
		break;
	case 1:
		if (w + 1 < 10)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h, w + 1);
		}
		else
		{
			dir_turn = 3;
			Shooting(h, w);
		}
		break;
	case 2:
		if (h + 1 < 10)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h + 1, w);
		}
		else
		{
			dir_turn = 0;
			Shooting(h, w);
		}
		break;
	case 3:
		if (w - 1 >= 0)
		{
			dir_history[dir_history_counter] = dir_turn;
			dir_history_counter++;
			Enemy_turn_t2(h, w - 1);
		}
		else
		{
			dir_turn = 1;
			Shooting(h, w);
		}
		break;
	}
}


int My_check_destroy(int i, int j)
{
	int count = 0;
	if (my_fleet[i - 1][j] == 1)
		count++;
	if (my_fleet[i][j - 1] == 1)
		count++;
	if (my_fleet[i][j + 1] == 1)
		count++;
	if (my_fleet[i + 1][j] == 1)
		count++;;
	return count;
}

void Shooting_correction()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (my_fleet[i][j] == 3)
			{
				if ((i - 1 >= 0) && (j - 1 >= 0))
					my_fleet[i - 1][j - 1] = 2;
				if ((i - 1 >= 0) && (my_fleet[i - 1][j] != 3))
					my_fleet[i - 1][j] = 2;
				if ((i - 1 >= 0) && (j + 1 < 10))
					my_fleet[i - 1][j + 1] = 2;
				if ((j - 1 >= 0) && (my_fleet[i][j - 1] != 3))
					my_fleet[i][j - 1] = 2;
				if ((j + 1 < 10) && (my_fleet[i][j + 1] != 3))
					my_fleet[i][j + 1] = 2;
				if ((i + 1 < 10) && (j - 1 >= 0))
					my_fleet[i + 1][j - 1] = 2;
				if ((i + 1 < 10) && (my_fleet[i + 1][j] != 3))
					my_fleet[i + 1][j] = 2;
				if ((i + 1 < 10) && (j + 1 < 10))
					my_fleet[i + 1][j + 1] = 2;
			}
}