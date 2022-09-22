#include "stdio.h"
#include "typedefs.h"
#include "stdlib.h"

extern u8_t count_entries;

typedef enum { true, false } bool;

struct list
{
	u32_t Student_ID;
	u32_t Student_Year;
	u32_t subjects[3];
	u32_t grades[3];
	struct list *next;
};


bool SDB_IsFull(void);
u8_t SDB_GetUsedSize(void);
bool SDB_AddEntry(u32_t id, u32_t year, u32_t* subjects, u32_t* grades);
void SDB_DeleteEntry(u32_t id);
bool SDB_ReadEntry(u32_t id);
void SDB_GetIdList(void);
bool SDB_IsIdExist(u32_t id);
