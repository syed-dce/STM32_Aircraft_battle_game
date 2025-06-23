#include "util.h"

#define KEY0_Pin GPIO_PIN_5
#define KEY0_GPIO_Port GPIOC

void KEY0_to_skip(void){
	while(1){
			if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){break;}
			else{HAL_Delay(10);}
		}
}

