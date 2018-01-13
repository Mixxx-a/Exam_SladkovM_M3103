#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define bat_length 10

#define cell_empty 0
#define cell_ship 1
#define cell_nothing 2
#define cell_destroyed 3

#define placed 1
#define not_placed 0

#define dir_nothing -1
#define dir_up 0
#define dir_right 1
#define dir_down 2
#define dir_left 3


int my_fleet[bat_length][bat_length];
int enemy_fleet[bat_length][bat_length];
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
void Place_enemy_ship(int decks);
void Enemy_correction();

int My_turn();
int Enemy_check_destroy(int i, int j);

int Enemy_turn_t1();
int Enemy_turn_t2(int h, int w);
void Shooting(int h, int w);
int My_check_destroy(int i, int j);
void Shooting_correction();

void Print_my_fleet();
void Print_enemy_fleet();
int Battle_easy();
int Battle_normal();
