/**
 * @file main.c
 * @author MohamedYouness (mohfathy2001@gmail.com)
 * @brief This file contains the project main code
 * @version 3.0
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "project.h"

u8_t count_entries=0;

int main(void)
{
u32_t Student_ID,Student_Year;
u32_t subjects[3];
u32_t grades[3];
static u8_t count=0;
u8_t IsFull,UsedSize,add_entry,read_entry,existence;	
u32_t choice;	
printf("Welcome to Database Module.\nNote: The maximum size of the database is 10 entries only.");

while(1)
 {
	printf("What do you want to do ?\nAdd an entry: (press 1)\nRead an entry: (press 2)\
	\nRemove an entry: (press 3)\nCheck existence of an entry: (press 4)\nView list of entries: (press 5)\
	\nExit: (press 6)\nyour choice : ");
	scanf("%d",&choice);

    switch(choice)
	{
		case (1) :
		{
            UsedSize=SDB_GetUsedSize();
			printf("The used size of the database = %d\n",UsedSize);
			IsFull=SDB_IsFull();
			if (IsFull==0)
			{
				printf("Enter your ID : ");
				scanf("%d",&Student_ID);
				printf("Enter your Year : ");
				scanf("%d",&Student_Year);
				for (int index = 0; index < 3; ++index)
				{
					printf("Enter the ID of course %d : ",index+1);
					scanf("%d",&subjects[index]);
					printf("Enter the grade of course %d (out of 100): ",index+1);
					scanf("%d",&grades[index]);
					while(grades[index]>100)
					{
						printf("Invalid grade\n");
						printf("Enter the grade of course %d (out of 100): ",index+1);
						scanf("%d",&grades[index]);
					}
				}

				add_entry=SDB_AddEntry(Student_ID, Student_Year, &subjects[0], &grades[0]);

				if (add_entry==1)
				{
					printf("The entry is created successfully\n");
					++count;
					count_entries=count;
				}
				else
				{
					printf("The entry is not created\n");
					break;
				}
			}
			else
			{
				printf("The database is full.\nNote: The maximum size of the database is 10 entries only.\n");
			}

			break;

		}
        case (2) :
		{
			u32_t id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			read_entry=SDB_ReadEntry(id);
			if (read_entry==1)
			{
				printf("Your ID exist\n");
			}
			else
			{
				printf("Your ID not exist\n");
			}
			break;
		}
		case (3) :
		{
			u32_t id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			SDB_DeleteEntry(id);
			break;
		}
		case (4) :
		{
			u32_t id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			existence=SDB_IsIdExist(id);
			if (existence==1)
			{
				printf("Your ID exist\n");
			}
			else
			{
				printf("Your ID not exist\n");
			}
			break;
		}
		case (5) :
		{
			SDB_GetIdList();
			break;
		}
		case (6) :
		{
			break;
		}
		default :
		{
			printf("Invalid choice\n");
			break;
		}
    }
if(choice==6)
{
	break;
}
else{}

printf("");
}

return 0;
}