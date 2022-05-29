/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#include<stdio.h>
#include"STD_TYPES.h"
#include"Functions.h"
#include"Defines.h"

form Head;

void main(void)
{
	u32 mode,pass,state=false,index,op;
	while(true)
	{
		printf("1\tAdmin mode\n2\tUser mode\n3\tExit\nPlease choose the mode: ");
		scanf("%d",&mode);
		if(mode == Admin)
		{
			for(u32 i=0;i<max_trails;i++)
			{
				printf("please enter password: ");
				scanf("%d",&pass);
				if(pass == 1234)
				{
					state=true;
					break;
				}
				else
				{
					if(i!=max_trails-1)
					{
						printf("Please try again.\n");
					}
				}
			}
			if(state=true)
			{
				printf("welcome admin.\n");
				while(true)
				{
					printf("1\tAdd new patient\n2\tEdit patient record\n3\tReserve a slot with the doctor\n4\tCancel reservation\n5\texit\n");
					printf("Please choose the operation you want: ");
					scanf("%d",&op);
					if(op==Add_new_patient)
					{
						addnewpatient(&Head,Head.id);
					}
					else if(op==Edit_patient_record)
					{
						editpatientrecord(&Head,Head.id);
					}
					else if(op==Reserve_slot)
					{
						reserveslot(Head.id);
					}
					else if(op==Cancel_reserve)
					{
						cancelreserve(&Head,Head.id);
					}
					else if (op==Exit_Admin)
					{
						break;
					}
					else
					{
						printf("wrong choise\n");
					}
				}
			}
			printf("Thank you.\nGoodBye.\n");
		}
		else if(mode==User)
		{
			printf("welcome User.\n");
			while(true)
			{
				printf("1\tView patient record\n2\tview today's reservation\n3\texit\n");
				printf("Please choose the operation you want: ");
					scanf("%d",&op);
					if(op==View_Patient_record)
					{
						printpatientform(&Head,Head.id);
					}
					else if(op==View_Today_Reservation)
					{
						printreservation();
					}
					else if(op==Exit_User)
					{
						break;
					}
					else
					{
						printf("wrong choise.\n");
					}
			}
			printf("Thank you.\nGoodBye.\n");
		}
		else if(mode==Exit_Program)
		{
			break;
		}
		else
		{
			printf("wrong choise.\n");
		}
	}
	printf("Thank you.\nGoodBye.");
}