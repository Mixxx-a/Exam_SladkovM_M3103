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
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (my_fleet[i][j] == 2)
				my_fleet[i][j] = 0;
}

int Place_my_ship(int decks)
{
	int w, i, cor_cell = 1;
	char h;
	int ar_cells[8];
	printf("Input cells for %d decks ship (with spaces):\n", decks);
	for (i = 0; i < decks; i++)
	{
		scanf("%s", pos);
		h = pos[0];
		pos[0] = pos[1];
		pos[1] = pos[2];
		pos[2] = '\0';
		w = atoi(pos) - 1;
		ar_cells[2 * i] = Symbol_number(h);
		ar_cells[2 * i + 1] = w;
		if (my_fleet[Symbol_number(h)][w] != 0)
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
		my_fleet[ar_cells[2 * i]][ar_cells[2 * i + 1]] = 1;
		my_counter++;
	}
	if (Check_ship() == 0)
	{
		for (i = 0; i < decks; i++)
		{
			my_fleet[ar_cells[2 * i]][ar_cells[2 * i + 1]] = 0;
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
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (my_fleet[i][j] == 1)
				if (((i - 1 >= 0) && (my_fleet[i - 1][j] == 1)) || ((i + 1 < 10) && (my_fleet[i + 1][j] == 1)) || ((j - 1 >= 0) && (my_fleet[i][j - 1] == 1)) || ((j + 1 < 10) && (my_fleet[i][j + 1] == 1)))
					count++;
	if (count == my_counter)
		return 1;
	else
		return 0;
}

int Symbol_number(char sym)
{
	switch (sym)
	{
	case 'A':
	case 'a':
		return 0;
	case 'B':
	case 'b':
		return 1;
	case 'C':
	case 'c':
		return 2;
	case 'D':
	case 'd':
		return 3;
	case 'E':
	case 'e':
		return 4;
	case 'F':
	case 'f':
		return 5;
	case 'G':
	case 'g':
		return 6;
	case 'H':
	case 'h':
		return 7;
	case 'I':
	case 'i':
		return 8;
	case 'J':
	case 'j':
		return 9;
	}
}

char Number_symbol(int num)
{
	char sym;
	switch (num)
	{
	case 1:
		sym = 'a';
		return sym;
	case 2:
		sym = 'b';
		return sym;
	case 3:
		sym = 'c';
		return sym;
	case 4:
		sym = 'd';
		return sym;
	case 5:
		sym = 'e';
		return sym;
	case 6:
		sym = 'f';
		return sym;
	case 7:
		sym = 'g';
		return sym;
	case 8:
		sym = 'h';
		return sym;
	case 9:
		sym = 'i';
		return sym;
	case 10:
		sym = 'j';
		return sym;
	}
}

void My_correction()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (my_fleet[i][j] == 1)
			{
				if ((i - 1 >= 0) && (j - 1 >= 0))
					my_fleet[i - 1][j - 1] = 2;
				if ((i - 1 >= 0) && (my_fleet[i - 1][j] != 1))
					my_fleet[i - 1][j] = 2;
				if ((i - 1 >= 0) && (j + 1 < 10))
					my_fleet[i - 1][j + 1] = 2;
				if ((j - 1 >= 0) && (my_fleet[i][j - 1] != 1))
					my_fleet[i][j - 1] = 2;
				if ((j + 1 < 10) && (my_fleet[i][j + 1] != 1))
					my_fleet[i][j + 1] = 2;
				if ((i + 1 < 10) && (j - 1 >= 0))
					my_fleet[i + 1][j - 1] = 2;
				if ((i + 1 < 10) && (my_fleet[i + 1][j] != 1))
					my_fleet[i + 1][j] = 2;
				if ((i + 1 < 10) && (j + 1 < 10))
					my_fleet[i + 1][j + 1] = 2;
			}
}