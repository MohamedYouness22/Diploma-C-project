/**
 * @file functions.c
 * @author MohamedYouness (mohfathy2001@gmail.com)
 * @brief This file contains the project funtions body
 * @version 2.0
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "project.h"

static struct list *head=NULL;
static struct list *prev_entry=NULL;
struct list *temp_head,*prev_head;

/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/
bool SDB_IsFull(void)
{
     if (count_entries>=10)
     {
        return 1;
     }
     else
     {
        return 0;
     }

}
   
/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/
u8_t SDB_GetUsedSize(void)
{
    return count_entries;
}

/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/
bool SDB_AddEntry(u32_t id, u32_t year, u32_t* subjects, u32_t* grades)
{
    struct list*entry;
    entry=malloc(sizeof(struct list));
    entry->next=NULL;
	entry->Student_ID=id;
	entry->Student_Year=year;
	entry->subjects[0]=*(subjects);
	entry->subjects[1]=*(subjects+1);
	entry->subjects[2]=*(subjects+2);
	entry->grades[0]=*(grades);
	entry->grades[1]=*(grades+1);
	entry->grades[2]=*(grades+2);
    if(head=NULL)
    {
        head=entry;
        temp_head=head;
    }
    else
    {
        prev_entry->next=entry;
    }
    prev_entry=entry;

	if (entry->next==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/
void SDB_DeleteEntry(u32_t id)
{
    struct list*temp;
    while(1)
	{
		if (head==temp_head)
		{
			if (head->Student_ID==id)
			{
				temp=head;
				head=head->next;
				temp_head=head;
				prev_entry=head;
				free(temp);
				printf("Your ID is removed from database\n");
				--count_entries;
				break;
			}
			else
			{
				prev_head=head;
				head=head->next;
			}
		}
		else if (head->next==NULL)
		{
			if (head->Student_ID==id)
			{
				temp=head;
				prev_head->next=NULL;
				prev_entry=prev_head;
				head=temp_head;
				free(temp);
				printf("Your ID is removed from database\n");
				--count_entries;
				break;
			}
			else
			{
				printf("Your ID not exist\n");
				head=temp_head;
				break;
			}
			
		}
		else
		{
			if (head->Student_ID==id)
			{
				temp=head;
				prev_head->next=head->next;
				head=temp_head;
				free(temp);
				printf("Your ID is removed from database\n");
				--count_entries;
				break;
			}
			else
			{
				prev_head=head;
				head=head->next;
			}
		}
	}	
}

/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/
bool SDB_ReadEntry(u32_t id)
{
    while(1)
	{
		if(head!=NULL)
		{	
			if (head->Student_ID==id)
			{
				printf("You ID : %d\n",head->Student_ID);
				printf("Your Year : %d\n",head->Student_Year);
				printf("Subject ID : %d its grade: %d\n",head->subjects[0],head->grades[0]);
				printf("Subject ID : %d its grade: %d\n",head->subjects[1],head->grades[1]);
				printf("Subject ID : %d its grade: %d\n",head->subjects[2],head->grades[2]);
				head=temp_head;
				return 1;
				break;
			}
			else
			{
				head=head->next;
			}
				
		}
		else
		{
			head=temp_head;
			return 0;
			break;
		}
	}
	
}

/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/

void SDB_GetIdList(void)
{
  printf("the number of entries currently exists in the database : %d\n",count_entries);
	printf("the list of IDs : \n");
	while(1)
	{
		if(head!=NULL)
		{
			printf("%d\n",head->Student_ID);
			head=head->next;
		}
		else
		{
			head=temp_head;
			break;
		}
	}
}

/*<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool SDB_IsIdExist(u32_t id)
{
    while(1)
	{
		if (head!=NULL)
		{
			if (head->Student_ID==id)
			{
				head=temp_head;
				return 1;
			}
			else
			{
				head=head->next;
			}
		}
		else
		{
			head=temp_head;
			return 0;
		}

	}
}