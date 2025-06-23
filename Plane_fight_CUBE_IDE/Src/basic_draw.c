#include "lcd.h"
#include "basic_draw.h"

#define BULLET_COLOR MAGENTA


int cross_width = 15; 
int cross_height = 15;


int heart_width = 11;
int heart_height = 11;


int buttle_width = 3; 
int buttle_height = 3;

int star_width = 5;
int star_height = 9;



void draw_equal_triangle(int x, int y, int width, int height);

void draw_rectangle(int x, int y, int width, int height);

void draw_left_triangle(int x, int y, int width, int height);

void draw_right_triangle(int x, int y, int width, int height);

void draw_trapezoid(int x, int y, int upper_width, int lower_width, int height);

void draw_reversed_equal_triangle(int x, int y, int width, int height);

void draw_reversed_left_triangle(int x, int y, int width, int height);

void draw_reversed_right_triangle(int x, int y, int width, int height);
	
void draw_reversed_trapezoid(int x, int y, int upper_width, int lower_width, int height);
	
void draw_my_plane(int x, int y){
	draw_equal_triangle(x, y - 10, 6, 4);
	draw_rectangle(x - 2, y - 10, 4, 20);
	draw_left_triangle(x - 2, y + 2, 12, 9);
	draw_right_triangle(x + 2, y + 2, 12, 9);
	draw_trapezoid(x, y + 10, 6, 14, 4);
	
}

void draw_enemy_plane(int x ,int y){
	draw_reversed_equal_triangle(x, y + 10, 6, 4);
	draw_rectangle(x - 2, y - 10, 4, 20);
	draw_reversed_left_triangle(x + 2, y- 2, 12, 9);
	draw_reversed_right_triangle(x - 2, y - 2, 12, 9);
	draw_reversed_trapezoid(x, y - 10, 6, 14, 4);
}


void draw_boss(int x, int y){
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10,
		x11, y11, x12, y12, x13, y13, x14, y14, x15, y15, x16, y16, x17, y17, x18, y18, x19, y19,
	x20, y20, x21, y21, x22, y22;
	
	x1 = x - 15;
	y1 = y + 40;
	
	x2 = x + 15;
	y2 = y + 40;
	
	x3 = x - 20;
	y3 = y + 20;
	
	x4 = x + 20;
	y4 = y + 20;
	
	x5 = x3;
	y5 = y3 - 5;
	
	x6 = x4;
	y6 = y4 - 5;
	
	x7 = x5;
	y7 = y5 - 10;
	
	x8 = x6;
	y8 = y6 - 10;
	
	x9 = x7;
	y9 = y7 - 30;
	
	x10 = x8;
	y10 = y8 - 30;
	
	x11 = x9;
	y11 = y9 - 10;
	
	x12 = x10;
	y12 = y10 - 10;
	
	x13 = x11;
	y13 = y11 - 5;
	
	x14 = x12;
	y14 = y12 - 5;
	
	
	x15 = x5 - 10;
	y15 = y5;
	
	x16 = x6 + 10;
	y16 = y6;
	
	x17 = x7 - 10;
	y17 = y7;
	
	x18 = x8 +10;
	y18 = y8;
	
	x19 = x9 - 10;
	y19 = y9;
	
	x20 = x10 + 10;
	y20 = y10;
	
	x21 = x11 - 10;
	y21 = y11;
	
	x22 = x12 + 10;
	y22 = y12;
	
	LCD_DrawLine(x1, y1, x2, y2);
	LCD_DrawLine(x1, y1, x3, y3);
	LCD_DrawLine(x2, y2, x4, y4);
	
	LCD_DrawLine(x3, y3, x13, y13);
	LCD_DrawLine(x4, y4, x14, y14);
	LCD_DrawLine(x13, y13, x14, y14);
	
	LCD_DrawLine(x5, y5, x15, y15);
	LCD_DrawLine(x7, y7, x17, y17);
	
	LCD_DrawLine(x6, y6, x16, y16);
	LCD_DrawLine(x8, y8, x18, y18);
	
	LCD_DrawLine(x9, y9, x19, y19);
	LCD_DrawLine(x11, y11, x21, y21);
	
	LCD_DrawLine(x10, y10, x20, y20);
	LCD_DrawLine(x12, y12, x22, y22);
	
	LCD_DrawLine(x15, y15 + 10, x17, y17 - 10);
	LCD_DrawLine(x15, y15 + 10, x15 - 10, y15 + 10);
	LCD_DrawLine(x17, y17 - 10, x17 - 10, y17 - 10);
	LCD_DrawLine(x15 - 10, y15 + 10, x17 - 10, y17 - 10);
	
	LCD_DrawLine(x19, y19 + 10, x21, y21 - 5);
	LCD_DrawLine(x19, y19 + 10, x19 - 10, y19 + 10);
	LCD_DrawLine(x21, y21 - 5, x21 - 10, y21 - 5);
	LCD_DrawLine(x19 - 10, y19 + 10, x21 - 10, y21 - 5);
	
	LCD_DrawLine(x16, y16 + 10, x18, y18 - 10);
	LCD_DrawLine(x16, y16 + 10, x16 + 10, y16 + 10);
	LCD_DrawLine(x18, y18 - 10, x18 + 10, y18 - 10);
	LCD_DrawLine(x16 + 10, y16 + 10, x18 + 10, y18 - 10);
	
	LCD_DrawLine(x20, y20 + 10, x22, y22 - 5);
	LCD_DrawLine(x20, y20 + 10, x20 + 10, y20 + 10);
	LCD_DrawLine(x22, y22 - 5, x22 + 10, y22 - 5);
	LCD_DrawLine(x20 + 10, y20 + 10, x22 + 10, y22 - 5);
	

}


void draw_my_bullet(int x, int y){
	LCD_DrawPoint(x,y-1);
	
	LCD_DrawPoint(x-1,y);
	LCD_DrawPoint(x,y);
	LCD_DrawPoint(x+1,y);

	LCD_DrawPoint(x-1,y+1);
	LCD_DrawPoint(x,y+1);
	LCD_DrawPoint(x+1,y+1);
}

void draw_enemy_bullet(int x, int y){
	LCD_DrawPoint(x-1,y-1);
	LCD_DrawPoint(x,y-1);
	LCD_DrawPoint(x+1,y-1);
	
	LCD_DrawPoint(x-1,y);
	LCD_DrawPoint(x,y);
	LCD_DrawPoint(x+1,y);

	LCD_DrawPoint(x,y+1);
}

void draw_cross(int x, int y){
	LCD_DrawLine(x-cross_width/2,y-cross_height/2, x+cross_width/2,y+cross_height/2);
	LCD_DrawLine(x-cross_width/2,y+cross_height/2, x+cross_width/2,y-cross_height/2);
}

void draw_heart(int x, int y){
	LCD_DrawLine(x-heart_width/2,y-heart_height/2, x+heart_width/2,y+heart_height/2);
	LCD_DrawLine(x-heart_width/2,y+heart_height/2, x+heart_width/2,y-heart_height/2);
	
	LCD_DrawLine(x-heart_width/2,y, x+heart_width/2,y);
	LCD_DrawLine(x,y+heart_height/2, x,y-heart_height/2);
}


void draw_star(int x,int y){

	LCD_DrawLine(x,y-star_height/2, x,y+star_height/2);

	LCD_DrawLine(x-star_width/2,y, x+star_width/2,y);
}




void draw_equal_triangle(int x, int y, int width, int height){
	int x1,y1,x2,y2,x3,y3;
	x1 = x;
	y1 = y - height;
	
	x2 = x - width / 2;
	y2 = y;
	
	x3 = x + width / 2;
	y3 = y;
	
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);

}


void draw_rectangle(int x, int y, int width, int height){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = x;
	y1 = y;
	
	x2 = x + width;
	y2 = y;
	
	x3 = x1;
	y3 = y + height;
	
	x4 = x2;
	y4 = y3;
	
	//LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x4,y4,x2,y2);
	//LCD_DrawLine(x4,y4,x3,y3);
}

void draw_left_triangle(int x, int y, int width, int height){
	int x1, y1, x2, y2, x3, y3;
	x1 = x;
	y1 = y;
	
	x2 = x - width;
	y2 = y;
	
	x3 = x;
	y3 = y - height;
	
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x2,y2,x3,y3);
}

void draw_right_triangle(int x, int y, int width, int height){
	int x1, y1, x2, y2, x3, y3;
	x1 = x;
	y1 = y;
	
	x2 = x + width;
	y2 = y;
	
	x3 = x;
	y3 = y - height;
	
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x2,y2,x3,y3);
}

void draw_trapezoid(int x, int y, int upper_width, int lower_width, int height){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = x - upper_width/2;
	y1 = y;
	
	x2 = x + upper_width/2;
	y2 = y;
	
	x3 = x - lower_width/2;
	y3 = y + height;
	
	x4 = x + lower_width/2;
	y4 = y + height;
	
	//LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x4,y4,x2,y2);
	LCD_DrawLine(x4,y4,x3,y3);
	
}

void draw_reversed_equal_triangle(int x, int y, int width, int height){
	int x1, y1, x2, y2, x3, y3;
	
	x1 = x - width / 2;
	y1 = y;
	
	x2 = x + width / 2;
	y2 = y;
	
	x3 = x;
	y3 = y + height;
	
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x2,y2,x3,y3);
	
}

void draw_reversed_left_triangle(int x, int y, int width, int height){
	int x1, y1, x2, y2, x3, y3;
	
	x1 = x;
	y1 = y;
	
	x2 = x + width;
	y2 = y;
	
	x3 = x;
	y3 = y + height;
	
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x2,y2,x3,y3);
	
}

void draw_reversed_right_triangle(int x, int y, int width, int height){
	int x1, y1, x2, y2, x3, y3;
	
	x1 = x;
	y1 = y;
	
	x2 = x - width;
	y2 = y;
	
	x3 = x;
	y3 = y + height;
	
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x2,y2,x3,y3);
	
}

void draw_reversed_trapezoid(int x, int y, int upper_width, int lower_width, int height){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = x - upper_width/2;
	y1 = y;
	
	x2 = x + upper_width/2;
	y2 = y;
	
	x3 = x - lower_width/2;
	y3 = y - height;
	
	x4 = x + lower_width/2;
	y4 = y - height;
	
	//LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x1,y1,x3,y3);
	LCD_DrawLine(x4,y4,x2,y2);
	LCD_DrawLine(x4,y4,x3,y3);
	
}
