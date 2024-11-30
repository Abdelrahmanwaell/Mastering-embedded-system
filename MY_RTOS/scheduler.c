/*
 * scheduler.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Dell
 */

#include"Platform_Type.h"
#include"scheduler.h"
#include "MYRTOS_FIFO.h"

FIFO_BUFF_t Ready_QUEUE;
Task_ref* 	Ready_QUEUE_buff[100];
Task_ref MYRTOS_idleTask;
unsigned char Idle_Task_Led;

typedef enum {
	SVC_ACTIVATE_TASK,
	SVC_TERMINATE_TASK,
	SVC_TASK_WAITING_TIME
}SVC_ID;

 struct{
	Task_ref* OSTasks[100];
	unsigned int _S_MSP_Stack;
	unsigned int _E_MSP_Stack;
	unsigned int PSP_Task_Locator;
	unsigned int NO_ActiveTask;
	Task_ref* CurentTask;
	Task_ref* NextTask;

	enum{
		OSsuspend,
		OSrun
	}OS_modeID;

}OS_control;


__attribute ((naked)) void PendSV_Handler()
{
	//====================================
		//Save the Context of the Current Task
		//====================================
		//Get the Current Task "Current PSP from CPU register" as CPU Push XPSR,.....,R0
		OS_GET_PSP(OS_control.CurentTask->current_PSP);

		//using this Current_PSP (Pointer) tp store (R4 to R11)
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r4 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r5 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r6 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r7 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r8 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r9 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r10 " : "=r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP-- ;
		__asm volatile("mov %0,r11 " : "=r" (*(OS_control.CurentTask->current_PSP))  );

		//save the current Value of PSP
		//already saved in Current_PSP



		//====================================
		//Restore the Context of the Next Task
		//====================================
		if (OS_control.NextTask != NULL){
		OS_control.CurentTask = OS_control.NextTask ;
		OS_control.NextTask = NULL ;
		}

		__asm volatile("mov r11,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r10,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r9,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r8,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r7,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r6,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r5,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;
		__asm volatile("mov r4,%0 " : : "r" (*(OS_control.CurentTask->current_PSP))  );
		OS_control.CurentTask->current_PSP++ ;

		//update PSP and exit
		OS_SET_PSP(OS_control.CurentTask->current_PSP);
		__asm volatile("BX LR");









}

void bubble_sort()
{	unsigned char i, j;
	Task_ref* temp;
	int n =OS_control.NO_ActiveTask;

	for(j=0;j<n-1;j++)
	{
		unsigned char flag =false ;
		for(i=0;i<n-j-1;i++)
		{
			if(OS_control.OSTasks[i]->priority > OS_control.OSTasks[i+1]->priority)
			{
				temp=OS_control.OSTasks[i];
				OS_control.OSTasks[i]    =  OS_control.OSTasks[i+1];
				OS_control.OSTasks[i+1]  =  temp;
				flag =true ;

			}

		}
		if (flag==false)
			break;
	}




}

void MYRTOS_Update_Schudlar_table()
{	Task_ref* temp = NULL;
	Task_ref* ptask ;
	Task_ref* pnextTask;
	int i=0;

	//bubble sort Sch. Table OS_conbtrol-> Tasks[100] ()priority high then low
	bubble_sort();
	//free ready queue
	while(FIFO_dequeue(&Ready_QUEUE,&temp) != FIFO_empty);
	//update ready queue
	while(i < OS_control.NO_ActiveTask)
	{	ptask =OS_control.OSTasks[i];
		pnextTask = OS_control.OSTasks[i+1];

		if(ptask->TaskState != Task_Suspend)
		{
			if(pnextTask->TaskState==Task_Suspend)
			{
				FIFO_enqueue(&Ready_QUEUE, ptask);
				ptask->TaskState=Task_Ready;
				break;
			}
			if(ptask->priority < pnextTask->priority)
			{
				FIFO_enqueue(&Ready_QUEUE, ptask);
				ptask->TaskState=Task_Ready;
				break;
			}
			else if(ptask->priority == pnextTask->priority)
			{
				FIFO_enqueue(&Ready_QUEUE, ptask);
				ptask->TaskState=Task_Ready;
			}

		}

		i++;
	}

}
void decide_Whatnxt()
{
	if((Ready_QUEUE.count==0) && (OS_control.CurentTask!= Task_Suspend ))
	{
		OS_control.CurentTask->TaskState=Task_Running;
		FIFO_enqueue(&Ready_QUEUE, OS_control.CurentTask);
		OS_control.NextTask =  OS_control.CurentTask;

	}
	else
	{
		FIFO_dequeue(&Ready_QUEUE, &OS_control.NextTask);
		OS_control.NextTask->TaskState=Task_Running;
		if((OS_control.CurentTask->priority == OS_control.NextTask->priority )  && (OS_control.CurentTask->TaskState != Task_Suspend ))
		{
			FIFO_enqueue(&Ready_QUEUE, OS_control.CurentTask);
			OS_control.CurentTask->TaskState= Task_Ready;

		}
	}
}
void OS_SVC_services(int * StackFramePointer)
{
	//OS_set_stack >> r0>>arg0=StackFramePointer
	//OS_set_stack >> r0 r1 r2 r3 r12 LR PC xPSR
	uint8 SVC_num = ((uint8 *)StackFramePointer[6])[-2];

	 switch (SVC_num)
	 {
		case SVC_ACTIVATE_TASK:			 //activate task
		case SVC_TERMINATE_TASK:		//terminate task
			//update schedular table , update ready queue
			MYRTOS_Update_Schudlar_table();
			//os is  in running state
			if(OS_control.OS_modeID==OSrun)
			{
				if(strcmp(OS_control.CurentTask->TaskName,"idleTask")!=0)
				{
				//decide what next
				decide_Whatnxt();

				//triger pendsv
				 OS_Trigger_PendSV();
				}

			}

			break;


	 case SVC_TASK_WAITING_TIME:
		 MYRTOS_Update_Schudlar_table();

		 break;
	 }

}



void MYRTOS_OS_SVC_SET(SVC_ID ID)
{
	switch (ID)
	{
	case SVC_ACTIVATE_TASK: //activate task
		__asm ("SVC  #0x0");
		break;

	case SVC_TERMINATE_TASK:
		__asm ("SVC  #0x1");
		break;

	case SVC_TASK_WAITING_TIME:
		__asm ("SVC  #0x2");
		break;

	}

}

void MYRTOS_create_MainStack()
{
	OS_control._S_MSP_Stack=&_estack;

	OS_control._E_MSP_Stack=OS_control._S_MSP_Stack - MAIN_STACK_SIZE;
	//allign 8 bytes between MSP and PSP
	OS_control.PSP_Task_Locator=OS_control._E_MSP_Stack-8;

}


void MYRTOS_IdleTask()
{
	while(1)
	{
		Idle_Task_Led^=1;
		__asm("wfe");
	}

}

MYRTOS_errorID MYRTOS_init()
{
	MYRTOS_errorID error = NOERROR;
	//update os mode(suspended)
	OS_control.OS_modeID=OSsuspend;
	//specify masin stack
	MYRTOS_create_MainStack();
	//Create OS Ready Queue
	if(FIFO_init(&Ready_QUEUE, Ready_QUEUE_buff, 100)!=FIFO_no_error)
	{
		error+=Ready_Queue_init_error ;
	}
	//Configure IDLE TASK
	strcpy(MYRTOS_idleTask.TaskName,"idleTask");
	MYRTOS_idleTask.priority=255;
	MYRTOS_idleTask.p_TaskEntry=MYRTOS_IdleTask;
	MYRTOS_idleTask.stack_size=300;
	error+= MYRTOS_CreateTask(& MYRTOS_idleTask);



	return error ;
}




void MYRTOS_Create_TaskStack(Task_ref* Tref)
{
	/*Task Frame
		 * ======
		 * XPSR
		 * PC (Next Task Instruction which should be Run)
		 * LR (return register which is saved in CPU while TASk1 running before TaskSwitching)
		 * r12
		 * r3
		 * r2
		 * r1
		 * r0
		 *====
		 *r4 ,r5, r6 , r7 ,r8 ,r9, r10,r11 (Saved/Restore)Manual
		 */
		Tref->current_PSP=Tref->_S_PSP_Task;
		Tref->current_PSP--;
		*(Tref->current_PSP) = 0x01000000;         //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000

		Tref->current_PSP--;
		*(Tref->current_PSP) =(unsigned int )Tref->p_TaskEntry; //pc

		Tref->current_PSP--;
		*(Tref->current_PSP) =0xFFFFFFED; //LR

		for(int j =0;j<13;j++)
		{
			Tref->current_PSP--;
			*(Tref->current_PSP)=0;
		}

}

MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Tref)
{
	MYRTOS_errorID error = NOERROR;
	//create its own PSP stack
	Tref->_S_PSP_Task=OS_control.PSP_Task_Locator;
	Tref->_E_PSP_Task=Tref->_S_PSP_Task - Tref->stack_size;
	//check stack size if exceeded psp stack
	if (Tref->_E_PSP_Task < (unsigned int )(&(_eheap)))
	{
		return Task_exceeded_StackSize;
	}
	// allign 8 bytes
	OS_control.PSP_Task_Locator=Tref->_E_PSP_Task - 8;

	//Intialize PSP task stack
	MYRTOS_Create_TaskStack(Tref);

	//update scheduler table
	OS_control.OSTasks[OS_control.NO_ActiveTask]=Tref;
	OS_control.NO_ActiveTask++;

	//task state update -> suspend
	Tref->TaskState=Task_Suspend;
	return error;
}

void MYRTOS_ActivateTask(Task_ref* Tref)
{
	Tref->TaskState=Task_Waiting;
	MYRTOS_OS_SVC_SET(SVC_ACTIVATE_TASK);
}

void MYRTOS_TerminateTask (Task_ref* Tref)
{
	Tref->TaskState = Task_Suspend ;
	MYRTOS_OS_SVC_SET(SVC_TERMINATE_TASK);
}

void MYRTOS_TaskTimeWaiting(unsigned int Ticks,Task_ref* Tref)
{
	Tref->TaskState = Task_Suspend;

	Tref->TimingWaiting.blocking=enable;
	Tref->TimingWaiting.TimeTicking=Ticks;
	MYRTOS_OS_SVC_SET(SVC_TERMINATE_TASK);

}

void MYRTOS_Update_Task_Wait_Time()
{	unsigned int i=0;
	for(i=0;i<OS_control.NO_ActiveTask;i++)
	{
		if(OS_control.OSTasks[i]->TaskState==Task_Suspend)
		{
			if(OS_control.OSTasks[i]->TimingWaiting.blocking == enable)
			{
				OS_control.OSTasks[i]->TimingWaiting.TimeTicking--;
				if(OS_control.OSTasks[i]->TimingWaiting.TimeTicking==1)
				{
					OS_control.OSTasks[i]->TimingWaiting.blocking = disable;
					OS_control.OSTasks[i]->TaskState=Task_Waiting;
					MYRTOS_OS_SVC_SET(SVC_TASK_WAITING_TIME);


				}

			}

		}
	}

}


void MYRTOS_Start_OS()
{
	OS_control.OS_modeID=OSrun;
	OS_control.CurentTask= &MYRTOS_idleTask;
	MYRTOS_ActivateTask(&MYRTOS_idleTask);
	Start_Ticker();
	OS_SET_PSP(OS_control.CurentTask->current_PSP);
	OS_SWITCH_SP_to_PSP;
	SWITCH_CPU_NONPRIVILEGED;
	MYRTOS_idleTask.p_TaskEntry();


}



MYRTOS_errorID MYRTOS_AcquireMutex(Mutex_ref* Mref , Task_ref* Tref)
{
	if(Mref->Current_TUser == NULL)
	{
		Mref->Current_TUser=Tref;
	}
	else
	{
		if(Mref->Next_TUser == NULL)
		{
			Mref->Next_TUser=Tref;
			Tref->TaskState=Task_Suspend;
			MYRTOS_OS_SVC_SET(SVC_TERMINATE_TASK);
		}
		else
		{
			return MutexisReachedToMaxNumberOfUsers;
		}

	}
	return NOERROR;
}
void MYRTOS_ReleaseMutex(Mutex_ref* Mref)
{
	if(Mref->Current_TUser!=NULL)
	{
		Mref->Current_TUser=Mref->Next_TUser;
		Mref->Next_TUser=NULL;
		Mref->Current_TUser->TaskState=Task_Waiting;
		MYRTOS_OS_SVC_SET(SVC_ACTIVATE_TASK);
	}
}
