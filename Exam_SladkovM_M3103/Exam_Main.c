#include "Exam.h"

int main(void)
{
	int ch, win;
	my_counter = 0;
	enemy_counter = 18;
	for (int i = 0; i <= bat_length; i++)
		for (int j = 0; j <= bat_length; j++)
		{
			my_fleet[i][j] = cell_empty;
			enemy_fleet[i][j] = cell_empty;
		}
	printf("Welcome to naval battle!\nThe battleground's height is A - J and width is 1 - 10\nI recommend you to prepare a paper because it's completely text game\n You must place:\n 1 4-decks ship\n 2 3-decks ships\n 4 2-decks ships\nPlease input your cells for ships like <b2 b3 b4 b5> \n");
	Place_my_fleet();
	Place_enemy_fleet();
	while (1)
	{
		printf("Press a key:\n 1)Play the game with easy bot (random shooting)\n 2)Play the game with normal bot (clever shooting)\n 3)Check your fleet\n 4)Check enemy fleet(CHEATS!!!)\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			win = Battle_easy();
			if (win == 1)
				printf("You won!");
			else
				printf("Bot won :(");
			_getch();
			return 0;
		case 2:
			win = Battle_normal();
			if (win == 1)
				printf("You won!");
			else
				printf("Bot won :(");
			_getch();
			return 0;
		case 3:
			Print_my_fleet();
			break;
		case 4:
			Print_enemy_fleet();
			break;
		default:
			printf("Unknown key. Try again.\n");
		}
	}
}