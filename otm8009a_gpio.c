#include "stm32h7xx_hal.h"
#include "lcd_gpio.h"

void hard_rst(void) {
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET); //rst,active low
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET); //resume
	HAL_Delay(500);
}

void set_16bits(uint16_t temp_16bits) {

	if ((temp_16bits & 0x1) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); //1
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x2) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); //2
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x4) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET); //3
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x8) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET); //4
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x10) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET); //5
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x20) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); //6
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x40) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); //7
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x80) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); //8
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x100) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); //9
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x200) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); //10
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x400) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //11
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x800) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); //12
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x1000) == 0) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET); //13
	} else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x2000) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET); //14
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x4000) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET); //15
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
	}
	if ((temp_16bits & 0x8000) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET); //16
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
	}

}

void send_one_cmd(uint16_t cmd) {
	//set all 4 ctl pins to default
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //dc high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); //rd high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); //wr high
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET); //cs high

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); //dc set as cmd
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET); //cs set as low(active)
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);  //rd set as  high
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET); //wr set as low (chip reads the risng edge of wrx
	set_16bits(cmd);
	//HAL_Delay(1); //sending cmd
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); //wr set as high ( CRIDICAL MOMENT!!!)

	//set all 4 ctl pins to default
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);  //dc high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);  //rd high
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);  //cs high
}

void send_one_data(uint16_t data) {
	//set all 4 ctl pins to default
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //dc high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); //rd high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); //wr high
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET); //cs high

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //dc set as data
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET); //cs set as low(active)
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);  //rd set as  high
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET); //wr set as low (chip reads the risng edge of wrx
	set_16bits(data);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); //wr set as high ( CRIDICAL MOMENT!!!)

	//set all 4 ctl pins to default
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);  //dc high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);  //rd high
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);  //cs high
}

void send_gram(uint16_t data) {
	//set all 4 ctl pins to default
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //dc high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); //rd high
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); //wr high
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET); //cs high

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //dc set as data
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET); //cs set as low(active)
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);  //rd set as  high
	set_16bits(data);
	for (uint32_t i_lcd = 0; i_lcd < 480 * 800; i_lcd++) { 
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET); //wr set as low (chip reads the risng edge of wrx)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); //wr set as high ( CRIDICAL MOMENT!!!)
	}
	//set  to default
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);  //cs high
}

void set_window_as_full_screen(void) {
	send_one_cmd(0x2a00); //set x start H
	send_one_data(0x00);
	send_one_cmd(0x2a01); //set x start L
	send_one_data(0x00);
	send_one_cmd(0x2a02); //set x end H
	send_one_data(0x01);
	send_one_cmd(0x2a03); //set x end L
	send_one_data(0xdf);

	send_one_cmd(0x2b00); //set y start H
	send_one_data(0x00);
	send_one_cmd(0x2b01); //set y start L
	send_one_data(0x00);
	send_one_cmd(0x2b02); //set y end H
	send_one_data(0x03);
	send_one_cmd(0x2b03); //set y end L
	send_one_data(0x1f);
}

void lcd_init(void) {
	//hard_rst();
	send_one_cmd(0x0100); //soft reset
	send_one_cmd(0x1100); //sleep out
	send_one_cmd(0x3800); //idle mode off
	send_one_cmd(0x2900); //display on
	send_one_cmd(0x1300); //normal display mode on
	send_one_cmd(0x3a00); //interface pixel format
	send_one_data(0x55); //16bits/pixel,one time transfer
	//send_one_cmd(0x2300); //all pixels on
	//must commented,otherwise will not display the desired
}

void lcd_clear(uint16_t color) {
	set_window_as_full_screen();
	send_one_cmd(0x2c00); //ready to write gram
	send_gram(color);
}
