#include "Exam.h"

void Print_my_fleet()
{
	printf("MY FLEET\n");
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (int i = 0; i < bat_length; i++)
	{
		printf("%c  ", Number_symbol(i + 1));
		for (int j = 0; j < bat_length; j++)
			printf("%d ", my_fleet[i][j]);
		printf("\n");
	}
}

void Print_enemy_fleet()
{
	printf("\n ENEMY FLEET\n");
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (int i = 0; i < bat_length; i++)
	{
		printf("%c  ", Number_symbol(i + 1));
		for (int j = 0; j < bat_length; j++)
			printf("%d ", enemy_fleet[i][j]);
		printf("\n");
	}
}

int Battle_easy()
{
	int win1, win2;
	while (1)
	{
		win1 = My_turn();
		if (win1 == 0)
			return 1;
		win2 = Enemy_turn_t1();
		if (win2 == 0)
			return 0;
	}
}

int Battle_normal()
{
	int win1, win2;
	for (int i = 0; i < 3; i++)
		dir_history[i] = -1;
	dir_history_counter = 0;
	h_old = -1;
	w_old = -1;
	dir_turn = -1;
	previous_shoot = 0;
	while (1)
	{
		win1 = My_turn();
		if (win1 == 0)
			return 1;
		win2 = Enemy_turn_t2(h_old, w_old);
		if (win2 == 0)
			return 0;
	}
}