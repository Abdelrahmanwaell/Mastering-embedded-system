/*
 * scheduler.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Dell
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include"CortexMX_OS_porting.h"

#define element_type Task_ref*

typedef enum{
	NOERROR,
	Ready_Queue_init_error,
	Task_exceeded_StackSize,
	MutexisReachedToMaxNumberOfUsers
}MYRTOS_errorID;

typedef enum {
	Task_Suspend,
	Task_Running,
	Task_Waiting,
	Task_Ready
}Task_StateID;

typedef struct{
	unsigned int stack_size;
	unsigned char priority;
	void(*p_TaskEntry )( void); // pointer to task function
	unsigned int _S_PSP_Task;	//not entered by user
	unsigned int _E_PSP_Task;	//not entered by user
	unsigned int* current_PSP;//not entered by user
	char TaskName[30];

	Task_StateID TaskState;

	struct {
		enum{
			disable,
			enable
		}blocking;
		unsigned int TimeTicking;
	}TimingWaiting;

}Task_ref;


typedef struct{
unsigned char* payload;
unsigned int   payloadSize;

Task_ref* Current_TUser;
Task_ref* Next_TUser;

char MutexName[30];




}Mutex_ref;


//APIs
MYRTOS_errorID MYRTOS_init();
MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Tref);
void MYRTOS_ActivateTask(Task_ref* Tref);
void MYRTOS_TerminateTask(Task_ref* Tref);
void MYRTOS_TaskTimeWaiting(unsigned int Ticks,Task_ref* Tref);
MYRTOS_errorID MYRTOS_AcquireMutex(Mutex_ref* Mref , Task_ref* Tref);
void MYRTOS_ReleaseMutex(Mutex_ref* Mref);

void MYRTOS_Start_OS();

#endif /* INC_SCHEDULER_H_ */
