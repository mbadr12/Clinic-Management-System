/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#ifndef __Functions_h__
#define __Functions_h__

#define Max_Length 50

typedef struct patient_information
{
	u8 name[Max_Length];
	u32 age;
	u8 gender;
	u32 id;
	u8 slot_num;
	struct patient_information* next;
}form;

void addnewpatient(form* Head,u32 id);
void editpatientrecord(form* Head,u32 id);
void reserveslot(u32 id);
void cancelreserve(form* Head,u32 id);
void printpatientform(form* Head,u32 id);
void printreservation(void);
u32 slotreserved(form* Head,u32 num);
form *idcheck(u32* id_state,u32 id);

#endif