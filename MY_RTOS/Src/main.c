/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include"stm32f103x6.h"
#include"scheduler.h"
#include"string.h"



Task_ref Task1, Task2, Task3, Task4 ;
unsigned char Task1_Led ,Task2_Led,Task3_Led,Task4_Led;
Mutex_ref Mutex1;

unsigned char Payload[3] = {1,2,3};

void task1()
{ static int count=0;
	while(1)
	{	count++;
		Task1_Led^=1;
		//task code
		if(count==100)
		{
			MYRTOS_AcquireMutex(&Mutex1, &Task1);
			MYRTOS_ActivateTask(&Task2);
		}
		//MYRTOS_TaskTimeWaiting(10,&Task1 );
		if(count==200)
		{
			count=0;
			MYRTOS_ReleaseMutex(&Mutex1);
		}

	}
}
void task2()
{ static int count=0;
	while(1)
	{

		Task2_Led^=1;
		//task code
		if(count==100)
		{
			MYRTOS_ActivateTask(&Task3);
		}
		if(count==200)
		{
			count =0;
			MYRTOS_TerminateTask(&Task2);

		}
	}
}
void task3()
{	static int count=0;
	while(1)
	{
		Task3_Led^=1;
		//task code
		if(count==100)
		{
			MYRTOS_ActivateTask(&Task4);
		}
		if(count==200)
		{
			count =0;
			MYRTOS_TerminateTask(&Task3);

		}

	}
}
void task4()
{ static int count =0;
	while(1)
	{	count++;
		Task4_Led^=1;
		//task code
		if(count==3)
		{
			MYRTOS_AcquireMutex(&Mutex1, &Task4);
		}
		if(count==200)
		{
			count=0;
			MYRTOS_ReleaseMutex(&Mutex1);
			MYRTOS_TerminateTask(&Task4);

		}
	}
}

int main(void)
{
	HW_init();

	MYRTOS_errorID error;

	if (MYRTOS_init() != NOERROR)
		while(1);


		Mutex1.payloadSize =3;
		Mutex1.payload =Payload;
		strcpy (Mutex1.MutexName, "Mutex_shared_T1_T4");

		Task1.stack_size = 1024 ;
		Task1.p_TaskEntry =task1;
		Task1.priority= 4 ;
		strcpy (Task1.TaskName, "task1");

		Task2.stack_size = 1024 ;
		Task2.p_TaskEntry =task2;
		Task2.priority= 3 ;
		strcpy (Task2.TaskName, "task2");

		Task3.stack_size = 1024 ;
		Task3.p_TaskEntry =task3;
		Task3.priority= 2 ;
		strcpy (Task3.TaskName, "task3");

		Task4.stack_size = 1024 ;
		Task4.p_TaskEntry =task4;
		Task4.priority= 1 ;
		strcpy (Task4.TaskName, "task4");

		error += MYRTOS_CreateTask(&Task1);
		error += MYRTOS_CreateTask(&Task2);
		error += MYRTOS_CreateTask(&Task3);
		error += MYRTOS_CreateTask(&Task4);

		MYRTOS_ActivateTask(&Task1);
//		MYRTOS_ActivateTask(&Task2);
//		MYRTOS_ActivateTask(&Task3);

		MYRTOS_Start_OS();




	while(1)
	{



	}



	return 0;

}


