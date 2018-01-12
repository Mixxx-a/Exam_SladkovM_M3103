#include "Exam.h"

int main(void)
{
	int i, j, ch, win1, win2;
	my_counter = 0;
	enemy_counter = 18;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
		{
			my_fleet[i][j] = 0;
			enemy_fleet[i][j] = 0;
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
			while (1)
			{
				win1 = My_turn();
				if (win1 == 0)
				{
					printf("You won!!!");
					_getch();
					return 0;
				}
				win2 = Enemy_turn_t1();
				if (win2 == 0)
				{
					printf("Bot won :(");
					_getch();
					return 0;
				}
			}
			break;
		case 2:
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
				{
					printf("You won!!!");
					_getch();
					return 0;
				}
				win2 = Enemy_turn_t2(h_old, w_old);
				if (win2 == 0)
				{
					printf("Bot won :(");
					_getch();
					return 0;
				}
			}
			break;
		case 3:
			printf("MY FLEET\n");
			printf("   1 2 3 4 5 6 7 8 9 10\n");
			for (i = 0; i < 10; i++)
			{
				printf("%c  ", Number_symbol(i + 1));
				for (j = 0; j < 10; j++)
					printf("%d ", my_fleet[i][j]);
				printf("\n");
			}
			break;
		case 4:
			printf("\n ENEMY FLEET\n");
			printf("   1 2 3 4 5 6 7 8 9 10\n");
			for (i = 0; i < 10; i++)
			{
				printf("%c  ", Number_symbol(i + 1));
				for (j = 0; j < 10; j++)
					printf("%d ", enemy_fleet[i][j]);
				printf("\n");
			}
			break;
		default:
			printf("Unknown key. Try again.\n");
		}
	}
}