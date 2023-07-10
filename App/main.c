/*
 * Scheduler.c
 *
 * Created: 08/07/2023 09:51:14 م
 * Author : ascom
 */ 

//#include <avr/io.h>

#include "StdTypes.h"
#include "BitMath.h"
#include "Scheduler.h"
//#include "Dio.h"
#include "Reg.h"




void LED1TOG(void)
{
	SetBit(DDRA,0);
	TogBit(PORTA,0);
}

void LED2TOG(void)
{
	SetBit(DDRA,1);
	TogBit(PORTA,1);
}

void LED3TOG(void)
{
	SetBit(DDRA,2);
	TogBit(PORTA,2);
}




int main(void)
{
	RTOS_CreateTask(1000,LED1TOG,0);
	RTOS_CreateTask(2000,LED2TOG,1);
	RTOS_CreateTask(3000,LED3TOG,2);
	RTOS_Start();
    while (1) 
    {
    }
}

