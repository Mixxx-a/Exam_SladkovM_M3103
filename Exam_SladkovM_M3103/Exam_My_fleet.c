#include "Exam.h"

void Place_my_fleet()
{
	Place_my_ship(4);
	My_correction();
	Place_my_ship(3);
	My_correction();
	Place_my_ship(3);
	My_correction();
	for (int i = 0; i < 4; i++)
	{
		Place_my_ship(2);
		My_correction();
	}
	for (int i = 0; i < bat_length; i++)
		for (int j = 0; j < bat_length; j++)
			if (my_fleet[i][j] == cell_nothing)
				my_fleet[i][j] = cell_empty;
}

int Place_my_ship(int decks)
{
	int w = 0, i, cor_cell = 1;
	char h;
	int ar_cells[8];
	printf("Input cells for %d decks ship (with spaces):\n", decks);
	for (i = 0; i < decks; i++)
	{
		scanf("%s", pos);
		h = pos[0];
		int j = 1;
		w = 0;
		while (pos[j] != '\0')
		{
			w = 10 * w + pos[j] - 48;
			j++;
		}
		w--;
		ar_cells[2 * i] = Symbol_number(h);
		ar_cells[2 * i + 1] = w;
		if (my_fleet[Symbol_number(h)][w] != cell_empty)
			cor_cell = 0;
	}
	if (cor_cell == 0)
	{
		printf("Cannot place like that! Try again.\n");
		Place_my_ship(decks);
		return 1;
	}
	for (i = 0; i < decks; i++)
	{

		my_fleet[ar_cells[2 * i]][ar_cells[2 * i + 1]] = cell_ship;
		my_counter++;
	}
	if (Check_ship() == 0)
	{
		for (i = 0; i < decks; i++)
		{
			my_fleet[ar_cells[2 * i]][ar_cells[2 * i + 1]] = cell_nothing;
			my_counter--;
		}
		printf("Cannot place like that! Try again.\n");
		Place_my_ship(decks);
		return 1;
	}
	else
		return 1;
}

int Check_ship()
{
	int count = 0;
	for (int i = 0; i < bat_length; i++)
		for (int j = 0; j < bat_length; j++)
			if (my_fleet[i][j] == cell_ship)
				if (((i - 1 >= 0) && (my_fleet[i - 1][j] == cell_ship)) 
					|| ((i + 1 < bat_length) && (my_fleet[i + 1][j] == cell_ship)) 
					|| ((j - 1 >= 0) && (my_fleet[i][j - 1] == cell_ship)) 
					|| ((j + 1 < bat_length) && (my_fleet[i][j + 1] == cell_ship)))
					count++;
	if (count == my_counter)
		return 1;
	else
		return 0;
}

int Symbol_number(char sym)
{
	int num = sym - 97;
	return num;
}

char Number_symbol(int num)
{
	char sym = num + 96;
	return sym;
}

void My_correction()
{
	for (int i = 0; i < bat_length; i++)
		for (int j = 0; j < bat_length; j++)
			if (my_fleet[i][j] == cell_ship)
			{
				if ((i - 1 >= 0) && (j - 1 >= 0))
					my_fleet[i - 1][j - 1] = cell_nothing;
				if ((i - 1 >= 0) && (my_fleet[i - 1][j] != cell_ship))
					my_fleet[i - 1][j] = cell_nothing;
				if ((i - 1 >= 0) && (j + 1 < bat_length))
					my_fleet[i - 1][j + 1] = cell_nothing;
				if ((j - 1 >= 0) && (my_fleet[i][j - 1] != cell_ship))
					my_fleet[i][j - 1] = cell_nothing;
				if ((j + 1 < bat_length) && (my_fleet[i][j + 1] != cell_ship))
					my_fleet[i][j + 1] = cell_nothing;
				if ((i + 1 < bat_length) && (j - 1 >= 0))
					my_fleet[i + 1][j - 1] = cell_nothing;
				if ((i + 1 < bat_length) && (my_fleet[i + 1][j] != cell_ship))
					my_fleet[i + 1][j] = cell_nothing;
				if ((i + 1 < bat_length) && (j + 1 < bat_length))
					my_fleet[i + 1][j + 1] = cell_nothing;
			}
}