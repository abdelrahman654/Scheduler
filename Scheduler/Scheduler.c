/*
 * Scheduler.c
 *
 * Created: 08/07/2023 09:59:11 م
 *  Author: ascom
 */ 
#include "Scheduler.h"

typedef struct
{
	u16 Periodicity;
	void (*TaskFunc)(void);	
}Task_t ;

Task_t SysTask[TASK_NUMBER] = {{0}};




void RTOS_Start(void)
{
	M_Timer0_Init();
	M_Timer0_SetCallBack(RTOS_Scheduler);
	M_Timer0_SetTime(1);
	M_Timer0_Start();
}

void RTOS_CreateTask(u16 Periodicity,void(*pfunc)(void),u8 Priority)
{
	if(SysTask[Priority].TaskFunc == 0)
	{
		SysTask[Priority].TaskFunc = pfunc;	
		SysTask[Priority].Periodicity = Periodicity;
	}
}

void RTOS_Scheduler(void)
{
	static u16 TickCounter = 0;
	TickCounter++;
	u8 i = 0;
	for(i = 0;i<TASK_NUMBER;i++)
	{
		if(SysTask[i].TaskFunc != 0)
		{
			if(TickCounter % SysTask[i].Periodicity == 0)
			{
				SysTask[i].TaskFunc();
			}
			else
			{
			}
		}
	}
}