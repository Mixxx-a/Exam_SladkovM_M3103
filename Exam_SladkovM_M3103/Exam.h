#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int my_fleet[10][10];
int enemy_fleet[10][10];
char pos[3];
int place_flag;
int my_counter, enemy_counter;
int my_num_cells, enemy_num_cells;
int h_old, w_old, h_started, w_started;
int dir_history[4], dir_history_counter;
int dir_turn;
int previous_shoot;

void Place_my_fleet();
int Place_my_ship(int decks);
int Check_ship();
int Symbol_number(char sym);
char Number_symbol(int num);
void My_correction();

void Place_enemy_fleet();
void Place_enemy_ship_4();
void Place_enemy_ship_3();
void Place_enemy_ship_2();
void Enemy_correction();

int My_turn();
int Enemy_check_destroy(int i, int j);

int Enemy_turn_t1();
int Enemy_turn_t2(int h, int w);
void Shooting(int h, int w);
int My_check_destroy(int i, int j);
void Shooting_correction();