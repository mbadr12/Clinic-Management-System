/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
#include"Functions.h"
#include"Defines.h"

u32 counter=0,slot[slots_avilable]={Not_Reserved};
extern form Head;

form *idcheck(u32* id_state,u32 id)
{
	form* ptr=&Head;
	while(ptr->next!=NULL)
	{
		if(id==ptr->id)
		{
			*id_state=true;
			break;
		}
		ptr=ptr->next;
	}
	if(id==ptr->id)
	{
		*id_state=true;
	}
	return ptr;
}

void addnewpatient(form* Head,u32 id)
{
	form* ptr=Head;
	u32 id_state=false;
	if(counter==0)
	{
		printf("please enter patient ID: ");
		scanf("%d",&Head->id);
		printf("Please enter Patient name: ");
		scanf("%s",&Head->name);
		printf("please enter patient age: ");
		scanf("%d",&Head->age);
		printf("please enter the gender of patient(f for female and m for male): ");
		scanf(" %c",&Head->gender);
		Head->slot_num=Not_Reserved;
		printf("\nThank you the patient has been added.\n\n");
		counter++;
	}
	else
	{
		printf("please enter patient ID: ");
		scanf("%d",&id);
		ptr=idcheck(&id_state,id);
		if(id_state==true)
		{
			printf("\n---------------------------------------\n\n");
			printf("The ID you entered is already used for another Patient.\n");
			printf("\n---------------------------------------\n\n");
		}
		else
		{
			form* new= (form*) malloc(sizeof(form));
			new->id=id;
			new->next=NULL;
			ptr->next=new;
			printf("Please enter Patient name: ");
			scanf("%s",&new->name);
			printf("please enter patient age: ");
			scanf("%d",&new->age);
			printf("please enter the gender of patient(f for female and m for male): ");
			scanf(" %c",&new->gender);
			new->slot_num=Not_Reserved;
			printf("\nThank you the patient has been added.\n\n");
		}
	}
}

void editpatientrecord(form* Head,u32 id)
{
	form* ptr=Head;
	u32 id_state=false;
	if(counter>0)
	{
		printf("please enter patient ID: ");
		scanf("%d",&id);
		if(ptr->id==id)
		{
			printf("Please enter Patient name: ");
			scanf("%s",&Head->name);
			printf("please enter patient age: ");
			scanf("%d",&Head->age);
			printf("please enter the gender of patient(f for female and m for male): ");
			scanf(" %c",&Head->gender);
			Head->slot_num=Not_Reserved;
			printf("\nThank you the patient record has been edited.\n\n");
		}
		else
		{
			ptr=idcheck(&id_state,id);
			if(id_state==false)
			{
				printf("worng ID.\n");
			}
			else
			{
				printf("Please enter Patient name: ");
				scanf("%s",&ptr->name);
				printf("please enter patient age: ");
				scanf("%d",&ptr->age);
				printf("please enter the gender of patient(f for female and m for male): ");
				scanf(" %c",&ptr->gender);
				ptr->slot_num=Not_Reserved;
				printf("\nThank you the patient record has been edited.\n\n");
			}
		}
	}
	
	else
	{
		printf("\n---------------------------------------\n\n");
		printf("The list still empety. No patient added.\n");
		printf("\n---------------------------------------\n\n");
	}
}
void reserveslot(u32 id)
{
	form* ptr;
	u32 id_state=false,slot_num,reserved=Not_Reserved;
	printf("please enter patient ID: ");
	scanf("%d",&id);
	ptr=idcheck(&id_state,id);
	if(id_state==false)
	{
		printf("\n---------------------------------------\n\n");
		printf("worng ID.\n");
		printf("\n---------------------------------------\n\n");
	}
	else if(ptr->slot_num!=Not_Reserved)
	{
		printf("\n---------------------------------------\n\n");
		printf("The patient has already reserved a slot before.\n");
		printf("\n---------------------------------------\n\n");
	}
	else
	{
		if(slot[First_slot]==Not_Reserved)
		{
			printf("To reserve the slot of 2pm to 2:30pm press 1.\n");
		}
		if(slot[Second_slot]==Not_Reserved)
		{
			printf("To reserve the slot of 2:30pm to 3pm press 2.\n");
		}
		if(slot[Third_slot]==Not_Reserved)
		{
			printf("To reserve the slot of 3pm to 3:30pm press 3.\n");
		}
		if(slot[Fourth_slot]==Not_Reserved)
		{
			printf("To reserve the slot of 4pm to 4:30pm press 4.\n");
		}
		if(slot[Fifth_slot]==Not_Reserved)
		{
			printf("To reserve the slot of 4:30pm to 5pm press 5.\n");
		}
		for(u32 j=0;j<slots_avilable;j++)
		{
			if(slot[j]==IS_Reserved)
			{
				reserved++;
			}
		}
		if(reserved==slots_avilable)
		{
			printf("\n---------------------------------------\n\n");
			printf("All slots have been reserved today.\n");
			printf("\n---------------------------------------\n\n");
		}
		else
		{
			printf("your choise: ");
			scanf("%d",&slot_num);
			if(slot_num>slots_avilable)
			{
				printf("\n---------------------------------------\n\n");
				printf("wrong choise\n");
				printf("\n---------------------------------------\n\n");
			}
			if(slot[slot_num-1]==IS_Reserved)
			{
				printf("\n---------------------------------------\n\n");
				printf("Sorry, the slot is already reserved.\n");
				printf("\n---------------------------------------\n\n");
			}
			else
			{
				slot[slot_num-1]=IS_Reserved;
				ptr->slot_num=slot_num;
				printf("Thank you slot has been reserved.\n\n");
			}
		}
	}
}

void cancelreserve(form* Head,u32 id)
{
	form* ptr=Head;
	u32 id_state=false,slot_num,reserved;
	for(u32 j=0;j<slots_avilable;j++)
	{
		if(slot[j]==IS_Reserved)
		{
			reserved++;
			break;
		}
	}
	if(reserved==Not_Reserved)
	{
		printf("\n---------------------------------------\n\n");
		printf("No slot has been reserved today.\n");
		printf("\n---------------------------------------\n\n");
	}
	else
	{
		printf("please enter patient ID: ");
		scanf("%d",&id);
		ptr=idcheck(&id_state,id);
		if(id_state==false)
		{
			printf("\n---------------------------------------\n\n");
			printf("worng ID.\n");
			printf("\n---------------------------------------\n\n");
		}
		else
		{
			if(ptr->slot_num==Not_Reserved)
			{
				printf("\n---------------------------------------\n\n");
				printf("The Patient has not reserved a slot.\n");
				printf("\n---------------------------------------\n\n");
			}
			else
			{
				slot[ptr->slot_num-1]=Not_Reserved;
				ptr->slot_num=Not_Reserved;
				printf("Thank you The slot has been canceled.\n\n");
			}
		}
	}
}

void printpatientform(form* Head,u32 id)
{
	form* ptr=Head;
	u32 id_state=false;
	if(counter>0)
	{
		printf("please enter patient ID: ");
		scanf("%d",&id);
		ptr=idcheck(&id_state,id);
		if(id_state==false)
		{
			printf("worng ID.\n");
		}
		else
		{
			printf("\n\n---------------------------------------\n\n");
			printf("patient ID: %d\n",ptr->id);
			printf("patient name: %s\n",ptr->name);
			printf("patient age: %d\n",ptr->age);
			printf("patient gender: %c\n",ptr->gender);
			printf("\n---------------------------------------\n\n");
		}
	}
	else
	{
		printf("\n---------------------------------------\n\n");
		printf("The list still empety. No patient was added.\n");
		printf("\n---------------------------------------\n\n");
	}	
}

u32 slotreserved(form* Head,u32 num)
{
	form* ptr=Head;
	while(ptr->next!=NULL)
	{
		if(ptr->slot_num==num)
		{
			break;
		}
		ptr=ptr->next;
	}
	return ptr->id;
}

void printreservation(void)
{
	u32 id,reserved=Not_Reserved;
	for(u32 j=0;j<slots_avilable;j++)
	{
		if(slot[j]==IS_Reserved)
		{
			reserved++;
			break;
		}
	}
	if(reserved==Not_Reserved)
	{
		printf("\n---------------------------------------\n\n");
		printf("No slot has been reserved today.\n");
		printf("\n---------------------------------------\n\n");
	}
	else
	{
		printf("\n---------------------------------------\n\n");
		if(slot[First_slot]==IS_Reserved)
		{
			id=slotreserved(&Head,First_slot+1);
			printf("slot of 2pm to 2:30pm ->ID: %d\n",id);
		}
		if(slot[Second_slot]==IS_Reserved)
		{
			id= slotreserved(&Head,Second_slot+1);
			printf("slot of 2:30pm to 3pm ->ID: %d\n",id);
		}
		if(slot[Third_slot]==IS_Reserved)
		{
			id=slotreserved(&Head,Third_slot+1);
			printf("slot of 3pm to 3:30pm ->ID: %d\n",id);
		}
		if(slot[Fourth_slot]==IS_Reserved)
		{
			id=slotreserved(&Head,Fourth_slot+1);
			printf("slot of 4pm to 4:30pm ->ID: %d\n",id);
		}
		if(slot[Fifth_slot]==IS_Reserved)
		{
			id= slotreserved(&Head,Fifth_slot+1);
			printf("slot of 5:30pm to 5pm ->ID: %d\n",id);
		}
		printf("\n---------------------------------------\n\n");
	}
}