#ifndef SDB_BY_LINKED_LIST_H_INCLUDED
#define SDB_BY_LINKED_LIST_H_INCLUDED
/****** Define data types ******/
typedef unsigned char uint8;
typedef char Int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;
typedef enum {false, true} bool;
#define NULL ((void *)0)

typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 struct student *  next; // to make a linked list
}student;


uint32 Enter_Id();
bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 * count, uint32 * list);
bool SDB_IsIdExist (uint32 id);

#endif // SDB_BY_LINKED_LIST_H_INCLUDED

