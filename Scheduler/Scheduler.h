/*
 * Scheduler.h
 *
 * Created: 08/07/2023 09:59:41 م
 *  Author: ascom
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/***************************************************************_INCLUDES_*********************************************************************/
#include "SchedulerCfg.h"
#include "StdTypes.h"
#include "Timer0.h"
/****************************************************************_MACROS_**********************************************************************/
/**************************************************************_PROTOTYPES_*******************************************************************/
void RTOS_CreateTask(u16,void(*)(void),u8);     //service
void RTOS_Scheduler(void);                      //ISR
void RTOS_Start(void);                          //service
void RTOS_KillTask(u8);                         //service
#endif /* SCHEDULER_H_ */