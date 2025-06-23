#include "run.h"
#include <stdlib.h>
#include <stdint.h>

#define KEY_WK_Pin GPIO_PIN_0
#define KEY_WK_GPIO_Port GPIOA
#define KEY0_Pin GPIO_PIN_5
#define KEY0_GPIO_Port GPIOC
#define LED0_Pin GPIO_PIN_8
#define LED0_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_15
#define KEY1_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOD


int left_limit = 2;
int right_limit = 238;
int up_limit = 42;
int down_limit = 318;


int check_overlap(int x, int y, int bound, int enemy_planes[10][2]){
	int i = 0;
	for(i = 0; i < bound*3; i++){
		if(enemy_planes[i][0] != 0 && (abs(enemy_planes[i][0]-x) <= 30 && abs(enemy_planes[i][1]-y) <= 30)){

			return 1;
		}
	}
	return 0;
}


void generate_enemy_planes(int level, int enemy_planes[10][2]){
	int i = 0;


	for(i=0; i<10; i++){
		if(enemy_planes[i][0] == 0){
			if(i < level*3){
				if(rand()%100 < level + 3){
					int x = rand()%210 + 14;
					int y = 61;
					int count = 0;
					while(check_overlap(x, y, level+1, enemy_planes) == 1 && count < 5){
						x = rand()%210 + 14;
						count++;
					}
					enemy_planes[i][0] = x;
					enemy_planes[i][1] = y;
				}
			}
			break;
		}
	}
}



void switch_my_act(int my_plane[2],int my_buttles[100][2]){
	int i=0;
	
	if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){
		LCD_Fill(my_plane[0]-14,my_plane[1]-14,	my_plane[0]+14,my_plane[1]+14,BACK_COLOR);
		if(my_plane[0]-3 > left_limit + 14){
			my_plane[0] = my_plane[0]-3;
		}
	}else if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){
		LCD_Fill(my_plane[0]-14,my_plane[1]-14,	my_plane[0]+14,my_plane[1]+14,BACK_COLOR);
		if(my_plane[0]+3 < right_limit -14){
			my_plane[0] = my_plane[0]+3;
		}
	}else if(HAL_GPIO_ReadPin(KEY_WK_GPIO_Port, KEY_WK_Pin) == GPIO_PIN_SET){
		LCD_Fill(my_plane[0]-14,my_plane[1]-14,	my_plane[0]+14,my_plane[1]+14,BACK_COLOR);
		for(i=0; i<100; i++){
			if(my_buttles[i][0] == 0){
				my_buttles[i][0] = my_plane[0];
				my_buttles[i][1] = my_plane[1]-15;
				break;
			}
		}
	}
}

	

void update_my_buttles(int my_buttles[100][2]){
	int i=0;
	
	for(i=0; i<100; i++){
		if(my_buttles[i][0] != 0){
			
			LCD_Fill(my_buttles[i][0]-1,my_buttles[i][1]-1,	my_buttles[i][0]+1,my_buttles[i][1]+1,BACK_COLOR);
			
			my_buttles[i][1] = my_buttles[i][1] - 3;
			
			
			if(my_buttles[i][1] < 42){				
				my_buttles[i][0] = 0;
				my_buttles[i][1] = 0;
			}
		}
	}
	
}


void update_enemy_buttles(int enemy_buttles[300][2], int level){
	int i=0;
	
	for(i=0; i<300; i++){
		if(enemy_buttles[i][0] != 0){
			
			LCD_Fill(enemy_buttles[i][0]-1,enemy_buttles[i][1]-1,	enemy_buttles[i][0]+1,enemy_buttles[i][1]+1,BACK_COLOR);
			
			enemy_buttles[i][1] = enemy_buttles[i][1] + level + 1;
			
			
			if(enemy_buttles[i][1] > 318){				
				enemy_buttles[i][0] = 0;
				enemy_buttles[i][1] = 0;
		
			}
		}
	}
}

void update_enemy_planes(int enemy_planes[10][2], int level){
	int i=0;
	
	for(i=0; i<10; i++){
		if(enemy_planes[i][0] != 0){
			
			LCD_Fill(enemy_planes[i][0]-14,enemy_planes[i][1]-14,	enemy_planes[i][0]+14,enemy_planes[i][1]+14,BACK_COLOR);
			
			enemy_planes[i][1] = enemy_planes[i][1] + level;
			
			if(enemy_planes[i][1] > 290){			
				enemy_planes[i][0] = 0;
				enemy_planes[i][1] = 0;
			}
		}
	}
}


void check_my_plane_to_enemy_plane_collide(int *score,int *life, int my_plane[2], int enemy_planes[10][2]){
	int i=0;
	int temp=0;
	
	for(i=0; i<10; i++){
		if(enemy_planes[i][0] != 0){
			
			if(abs(enemy_planes[i][0] - my_plane[0]) <= 28){
				if(abs(enemy_planes[i][1] - my_plane[1]) <= 28){
					LCD_Fill(my_plane[0]-14,my_plane[1]-14,	my_plane[0]+14,my_plane[1]+14,BACK_COLOR);
					LCD_Fill(enemy_planes[i][0]-14,enemy_planes[i][1]-14,	enemy_planes[i][0]+14,enemy_planes[i][1]+14,BACK_COLOR);
				
					my_plane[0] = 120;
					my_plane[1] = 290;
					
					enemy_planes[i][0] = 0;
					enemy_planes[i][1] = 0;
					
					temp = (*score);
					(*score) = temp+1;
					
					temp = (*life);
					(*life) = temp-1;
					
					HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
					HAL_Delay(20);
					HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
					
					break;
				}
			}
		}
	}
}


void check_my_buttles_to_enemy_plane_collide(int *score,	int my_buttles[100][2], int enemy_planes[10][2]){
	int i=0;
	int j=0;
	int temp=0;
	
	for(i=0; i<10; i++){
		if(enemy_planes[i][0] != 0){
			for(j=0; j<100; j++){
				
				if(abs(my_buttles[j][0] - enemy_planes[i][0]) <= 15){
					if(abs(my_buttles[j][1] - enemy_planes[i][1]) <= 15){
						LCD_Fill(enemy_planes[i][0]-14,enemy_planes[i][1]-14,	enemy_planes[i][0]+14,enemy_planes[i][1]+14,BACK_COLOR);

						my_buttles[j][0] = 0;
						my_buttles[j][1] = 0;
						
						enemy_planes[i][0] = 0;
						enemy_planes[i][1] = 0;
						
						temp = (*score);
						(*score) = temp+1;
						
						HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
						HAL_Delay(20);
						HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
					
						break;
					}
				}
			}
		}
	}
}

void check_my_buttles_to_boss_collide(int *score, int *boss_life,	int my_buttles[100][2], int boss[2]){
	int i = 0;
	int temp = 0;
	for(i=0; i<100; i++){
				
		if(my_buttles[i][0] != 0){
			if(abs(my_buttles[i][0] - boss[0]) <= 41){
					if(abs(my_buttles[i][1] - boss[1]) <= 41){
						LCD_Fill(boss[0]-40, boss[1] - 40, boss[0] + 40, boss[1] + 40,BACK_COLOR);
					
						my_buttles[i][0] = 0;
						my_buttles[i][1] = 0;
						
						temp = (*score);
						(*score) = temp+1;
						
						temp = (*boss_life);
						(*boss_life) = temp-1;
						
						HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
						HAL_Delay(20);
						HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			
						break;
					}
				}
		}
	}
}


void check_my_plane_to_enemy_buttles_collide(int *life,	int enemy_buttles[300][2], int my_plane[2]){
	int temp = 0;
	int i = 0;
	for(i=0; i<300; i++){
		if(enemy_buttles[i][0] != 0){
			if(abs(enemy_buttles[i][0] - my_plane[0]) <= 15){
					if(abs(enemy_buttles[i][1] - my_plane[1]) <= 15){
					  LCD_Fill(my_plane[0]-14,my_plane[1]-14,	my_plane[0]+14,my_plane[1]+14,BACK_COLOR);

					  my_plane[0] = 120;
					  my_plane[1] = 290;
						
					  enemy_buttles[i][0] = 0;
					  enemy_buttles[i][1] = 0;
						
						temp = (*life);
					 (*life) = temp-1;
						
					 HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
					 HAL_Delay(20);
					 HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
					
					  break;
					}
		}
	}
 }
}

void generate_enemy_buttles(int level, int enemy_plane[10][2],  int enemy_buttles[300][2]){
	int i = 0;
	int j = 0;
	for(i=0; i<10; i++){
		
		if(enemy_plane[i][0] != 0 && rand()%200 < level){
			for(j=0; j<300; j++){
				if(enemy_buttles[j][0] == 0){
					enemy_buttles[j][0] = enemy_plane[i][0];
					enemy_buttles[j][1] = enemy_plane[i][1] + 15;
					break;
				}
			}	
		}
	}
}

void generate_boss_buttles(int boss[2],  int enemy_buttles[300][2]){
	int i = 0;
	int j = 0;
	for(i=0; i<11; i++){
		
		if(rand()%200 < 3){
			for(j=0; j<300; j++){
				if(enemy_buttles[j][0] == 0){
					enemy_buttles[j][0] = boss[0] - 30 + i * 6;
					enemy_buttles[j][1] = boss[1] + 15;
					break;
				}
			}	
		}
	}
}

void clear_all_enemy_plane(int my_plane[2],	int enemy_plane[10][2], int my_buttles[100][2], int enemy_buttles[300][2]){
	int i=0;
	
	for(i=0; i<10; i++){
		enemy_plane[i][0] = 0;
		enemy_plane[i][1] = 0;
	}
	
	for(i=0; i<100; i++){
		if(my_buttles[i][0] != 0){
			my_buttles[i][0] = 0;
			my_buttles[i][1] = 0;
		}
	}
	
	for(i=0; i<300; i++){
		if(enemy_buttles[i][0] != 0){
			enemy_buttles[i][0] = 0;
			enemy_buttles[i][1] = 0;
		}
	}
	
	LCD_Fill(1,41,239,318,BACK_COLOR);
	draw_my_plane(my_plane[0],my_plane[1]);
}

void move_boss(int boss[2], int *pace){

		int temp = 0;
	    LCD_Fill(boss[0]-40, boss[1] - 40, boss[0] + 40, boss[1] + 40,BACK_COLOR);

	    boss[0] = boss[0] + (*pace);

		if(boss[0] < 43 || boss[0] > 197){
			temp = (*pace);
			(*pace) = -temp;
		}

}

