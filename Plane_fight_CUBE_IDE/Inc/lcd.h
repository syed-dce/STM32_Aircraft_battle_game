#ifndef __LCD_H
#define __LCD_H		
#include "main.h"
#include "stdlib.h"

 
typedef struct  
{										    
	uint16_t width;			
	uint16_t height;			
	uint16_t id;				
	uint8_t  dir;				
	uint16_t	wramcmd;		
	uint16_t setxcmd;		
	uint16_t  setycmd;		
}_lcd_dev; 	  

extern _lcd_dev lcddev;	
   
extern uint16_t  POINT_COLOR;   
extern uint16_t  BACK_COLOR; 


#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008
#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  
#define	LCD_LED PCout(10) 				
 
#define	LCD_CS_SET  GPIOC->BSRR=1<<9    
#define	LCD_RS_SET	GPIOC->BSRR=1<<8    	   
#define	LCD_WR_SET	GPIOC->BSRR=1<<7    
#define	LCD_RD_SET	GPIOC->BSRR=1<<6    
								    
#define	LCD_CS_CLR  GPIOC->BRR=1<<9     
#define	LCD_RS_CLR	GPIOC->BRR=1<<8     	   
#define	LCD_WR_CLR	GPIOC->BRR=1<<7     
#define	LCD_RD_CLR	GPIOC->BRR=1<<6       


#define DATAOUT(x) GPIOB->ODR=x; 
#define DATAIN     GPIOB->IDR;   	

 
#define L2R_U2D  0 
#define L2R_D2U  1 
#define R2L_U2D  2 
#define R2L_D2U  3 

#define U2D_L2R  4 
#define U2D_R2L  5 
#define D2U_L2R  6 
#define D2U_R2L  7 

#define DFT_SCAN_DIR  L2R_U2D  
	 
#define L2R_U2D  0 
#define L2R_D2U  1 
#define R2L_U2D  2 
#define R2L_D2U  3 

#define U2D_L2R  4 
#define U2D_R2L  5 
#define D2U_L2R  6 
#define D2U_R2L  7 	 

#define DFT_SCAN_DIR  L2R_U2D  


#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 
#define BRRED 			 0XFC07 
#define GRAY  			 0X8430 

#define DARKBLUE      	 0X01CF	
#define LIGHTBLUE      	 0X7D7C	 
#define GRAYBLUE       	 0X5458 
 
#define LIGHTGREEN     	 0X841F 
#define LGRAY 			 0XC618 

#define LGRAYBLUE        0XA651 
#define LBBLUE           0X2B12 
	    															  
void LCD_Init(void); // Initialization
void LCD_DisplayOn(void); // Open the display
void LCD_DisplayOff(void); // Close the display
void LCD_Clear(uint16_t Color); // Clear the screen with specific color
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);	// Set the position of cursor
void LCD_DrawPoint(uint16_t x,uint16_t y); // Set color for a point
void LCD_Fast_DrawPoint(uint16_t x,uint16_t y,uint16_t color); // Set color for a point(quicker)
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y); // Read the color of a point
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r); // Draw a circle
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2); // Draw a line
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);	// Draw a rectangle
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);	// Fill the area with color
void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color);	// Fill the area with color
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);	// Display a char
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size); // Display number without the leading zeros
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode); // Display number with the leading zeros
void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint8_t size, uint8_t *p); // Display a string

void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint16_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);		  
void LCD_Scan_Dir(uint8_t dir); // Set the scan direction
void LCD_Display_Dir(uint8_t dir); // Set the display direction
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);


#define LCD_WR_DATA(data){\
LCD_RS_SET;\
LCD_CS_CLR;\
DATAOUT(data);\
LCD_WR_CLR;\
LCD_WR_SET;\
LCD_CS_SET;\
} 


#define SSD_HOR_RESOLUTION		800		
#define SSD_VER_RESOLUTION		480		

#define SSD_HOR_PULSE_WIDTH		1		
#define SSD_HOR_BACK_PORCH		46		
#define SSD_HOR_FRONT_PORCH		210		

#define SSD_VER_PULSE_WIDTH		1		
#define SSD_VER_BACK_PORCH		23		
#define SSD_VER_FRONT_PORCH		22		

#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)
						  		 
#endif













