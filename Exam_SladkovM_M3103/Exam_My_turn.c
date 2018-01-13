#include "Exam.h"

int My_turn()
{
	char h;
	int w = 0;
	printf("\n Input cell for shoot\n");
	scanf("%s", pos);
	h = pos[0];
	int j = 1;
	while (pos[j] != '\0')
	{
		w = 10 * w + pos[j] - 48;
		j++;
	}
	w--;
	if (enemy_fleet[Symbol_number(h)][w] == cell_ship)
	{
		enemy_counter--;
		if (enemy_counter == 0)
			return 0;
		enemy_fleet[Symbol_number(h)][w] = cell_destroyed;
		if (my_num_cells == 0)
		{
			my_num_cells = Enemy_check_destroy(Symbol_number(h), w);
			printf("\n HIT! Shoot again!");
			My_turn();
		}
		else
		{
			my_num_cells = my_num_cells - 1 + Enemy_check_destroy(Symbol_number(h), w);
			if (my_num_cells == 0)
			{
				printf("\n You destroyed enemy ship! Shoot again");
				My_turn();
			}
			else
			{
				printf("\n HIT! Shoot again!");
				My_turn();
			}
		}
	}
	else
	{
		printf(" Missed. Enemy turn. \n\n");
		return 1;
	}
}

int Enemy_check_destroy(int i, int j)
{
	int count = 0;
	if (enemy_fleet[i - 1][j] == cell_ship)
		count++;
	if (enemy_fleet[i][j - 1] == cell_ship)
		count++;
	if (enemy_fleet[i][j + 1] == cell_ship)
		count++;
	if (enemy_fleet[i + 1][j] == cell_ship)
		count++;
	return count;
}