#include "lcd.h"
#include "draw.h"
#include <stdio.h>

void draw_start_page(void){
	LCD_ShowString(30,180,200,24,24,"Aircraft");
	LCD_ShowString(130,180,200,24,24,"Battle");
	
	draw_my_plane(120,120);
	
	LCD_ShowString(60,250,200,12,12,"PRESS KEY-0 TO START");
}

void init_play_interface(void){


	LCD_DrawLine(1,40,239,40);

	LCD_ShowString(8,7,100,24,24,"score");
	LCD_ShowString(130,7,100,24,24,"life");
}


void draw_end(int *score,int *score_2, int *score_3){
	LCD_Clear(GRAY);
	
	LCD_ShowString(60,30,200,24,24,"Game Over");
	LCD_ShowString(30,80,200,24,24,"My SCORE:");
	LCD_ShowxNum(130,80,*score,4,24,0);
	if(*score_2 == 0 && *score_3 == 0){
		*score_2 = *score;
		LCD_ShowString(30,140,200,24,24,"Rank1:");
		LCD_ShowxNum(130,140,*score_2,4,24,0);
		LCD_ShowString(30,200,200,24,24,"Rank2:");
		LCD_ShowString(160,200,200,24,24,"--");
	}else if(*score_2 != 0 && *score_3 == 0){
		if (*score > *score_2) {
			*score_3 = *score_2;
			*score_2 = *score;
		} else if (*score < *score_2) {
			*score_3 = *score;
		}
		LCD_ShowString(30,140,200,24,24,"Rank1:");
		LCD_ShowxNum(130,140,*score_2,4,24,0);
		LCD_ShowString(30,200,200,24,24,"Rank2:");
		LCD_ShowxNum(130,200,*score_3,4,24,0);
	}else if(*score_2 != 0 && *score_3 != 0){
		if (*score > *score_2) {
			*score_3 = *score_2;
			*score_2 = *score;
		} else if (*score < *score_2 && *score > *score_3) {
			*score_3 = *score;
		}
		LCD_ShowString(30,140,200,24,24,"Rank1:");
		LCD_ShowxNum(130,140,*score_2,4,24,0);
		LCD_ShowString(30,200,200,24,24,"Rank2:");
		LCD_ShowxNum(130,200,*score_3,4,24,0);
	}

	*score = 0;
	
	LCD_ShowString(60,280,200,12,12,"Powered by 2019SUSTech");
}



void draw_play_title(int score, int life){

	int i=0;
	int start_x = 195;
	
	//LCD_Fill(75,8,130,32,GRAY);
	LCD_ShowxNum(75,8,score,4,24,0);		
	
	LCD_Fill(190,15,226,25,BACK_COLOR);
	for(i=0; i<life; i++){	
		draw_heart(start_x+i*13, 20);
	}
}

//#define my_buttle_max 100
//#define enemy_buttle_max 300
//#define enemy_plane_max 10

//���� 0��0
void draw_all_my_buttles(int my_buttles[100][2]){
	int i =0;
	for(i=0; i<100; i++){
		if(my_buttles[i][0] != 0){
			draw_my_bullet(my_buttles[i][0],my_buttles[i][1]);
		}
	}
}


void draw_all_enemy_planes(int enemy_planes[10][2]){
	int i = 0;
	for(i=0; i<10; i++){
		if(enemy_planes[i][0] != 0){
			draw_enemy_plane(enemy_planes[i][0],enemy_planes[i][1]);
		}
	}
}


void draw_all_enemy_buttles(int enemy_buttles[300][2]){
	int i =0;
	for(i=0; i<300; i++){
		if(enemy_buttles[i][0] != 0){
			draw_enemy_bullet(enemy_buttles[i][0],enemy_buttles[i][1]);
		}
	}
}



void draw_play_all(int score,int life, int my_plane[2], int my_buttles[100][2], int boss[2], int enemy_planes[10][2], int enemy_buttles[300][2]){
	draw_play_title(score,life);
	
	draw_my_plane(my_plane[0],my_plane[1]);
	draw_all_my_buttles(my_buttles);
	if(boss[0]!= 0){
		draw_boss(boss[0],boss[1]);
	}
	draw_all_enemy_planes(enemy_planes);
	draw_all_enemy_buttles(enemy_buttles);
}

