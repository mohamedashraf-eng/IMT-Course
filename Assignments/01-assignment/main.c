/**
 * @File: main.c
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: the main entry point.
 *
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	HEADERS INCLUDED															-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "assignment_1.h"

/**
 * @brief main entry point.
 * @return int.
 */
int main(void)
{
	SYS_INIT();

	while(1)
	{

		LED_CTRL(GREEN, ON);
		SYS_SSD(SSD1, 1, 1);
		SYS_SSD(SSD2, 9, 1);
		LED_CTRL(GREEN, OFF);

		LED_CTRL(YELLOW, ON);
		SYS_SSD(SSD2, 3, 1);
		LED_CTRL(YELLOW, OFF);

		LED_CTRL(RED, ON);
		SYS_SSD(SSD1, 1, 1);
		SYS_SSD(SSD2, 9, 1);
		LED_CTRL(RED, OFF);

	}

	return 0;
}
