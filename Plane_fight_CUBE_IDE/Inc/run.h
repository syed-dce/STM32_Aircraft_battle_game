#ifndef __RUN_H
#define __RUN_H	
#include "util.h"
#include "draw.h"
#include "stm32f1xx_hal.h"
#include <stdlib.h>
#include <stdint.h>

void generate_enemy_planes(int level, int enemy_planes[10][2]);



void switch_my_act(int my_plane[2],int my_buttles[300][2]);


void update_my_buttles(int my_buttles[100][2]);

void update_enemy_buttles(int enemy_buttles[300][2], int level);


void update_enemy_planes(int enemy_planes[10][2], int level);

void check_my_plane_to_enemy_plane_collide(int *score,int *life, int my_plane[2], int enemy_planes[10][2]);
void check_my_buttles_to_enemy_plane_collide(int *score, int my_buttles[300][2], int enemy_planes[10][2]);

void check_my_plane_to_enemy_buttles_collide(int *life,	int enemy_buttles[300][2], int my_plane[2]);

void generate_enemy_buttles(int level, int enemy_plane[10][2], int enemy_buttles[300][2]);

void generate_boss_buttles(int boss[2], int enemy_buttles[300][2]);
	
void clear_all_enemy_plane(int my_plane[2],	int enemy_plane[10][2], int my_buttles[100][2], int enemy_buttles[300][2]);

void check_my_buttles_to_boss_collide(int *score, int *boss_life, int my_buttles[100][2], int boss[2]);

void move_boss(int boss[2], int *pace);
#endif
