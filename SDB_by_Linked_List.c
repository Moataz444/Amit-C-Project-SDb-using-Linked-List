#include <stdio.h>
#include <stdlib.h>
#include "SDB_by_Linked_List.h"
#define max_size 10 // database maximum size
uint32 id; // to store current id to be used
uint8 count= 0; // start database with 0 elements
uint32 list[10]; // list to contain all students id's

student* head=NULL; // make head = null at the beginning linked list
student* temp=NULL; // a temporary used to move in database

uint32 Enter_Id() // a function scan id from user
{
    printf("\nEnter Student_ID\n");
    scanf("%d",&id);
    return id;
}

bool isGrade_Ok(uint32 grade) // check if course grade is to store it
{
    if(grade>=0 && grade <=100)
        return true;
    else
    {
        printf("\nWrong Grade try again\n");
        return false;
    }
}

void store_all_id_to_List() // function used to store all new set of ids after deletion and entry
{
    temp=head;
    int i;
    for(i=0; (i<count  && temp!=NULL ) ; i++) // loop to store ids
    {
        list[i]=temp->Student_ID;
        temp=temp->next;
    }
}

bool SDB_IsFull ()
//Description: check if the database is full or not.
//Return: if the database is full return true else return false
{
    if(count==max_size) // check if full (max = 10)
    {
        printf("\nDatabase is Full\n");
        return true;
    }
    else
    {
        return false;
    }
}

uint8 SDB_GetUsedSize()
//Description: get how many students in your database have added
//Return: Return the number of students in the database.
 {
    printf("\nNumber of Students in database = %d\n", count);
 }

 bool SDB_AddEntry() // add to linked list
// Description: this function asks user to add one student to the database with the required data
//(Student_ID, Student_year, Course1_ID,Course1_grade, Course2_ID, Course2_grade, Course3_ID,  Course3_grade)

//check if the database is full or not

//Return:
//return 1 if the data is added successfully
//return 0 if the data entered by user is not correct and
{
    temp=NULL; //used to move between student
    uint32 grade; // to store grade and check it
    uint32 Student_ID;// to store id to check it

    if(SDB_IsFull()!=true)
    {
        student* node=(student*)malloc(sizeof(student));

        Student_ID=Enter_Id();
        while(1) // check if id already exists
        {
            if(SDB_IsIdExist(Student_ID)!= true) // if id doesn't exists
            {
                node->Student_ID = Student_ID; // then store id and data
                printf("Pass\n");
                break; // stops the loop
            }
            else // else re-enter id
            {
                printf("ERROR : Invalid ID enter a valid id\n");
                Student_ID=Enter_Id();
            }
        }

        printf("\nEnter Student year\n");
        scanf("%d",&node->Student_year);

        printf("\nEnter Course1 ID\n");
        scanf("%d",&node->Course1_ID);

        while(1) // check Course1 grade
        {
            printf("\nEnter Course1 grade\n");
            scanf("%d",&grade);
            if(isGrade_Ok(grade))
            {
                node->Course1_grade= grade;
                break;
            }

        }

        printf("\nEnter Course2 ID\n");
        scanf("%d",&node->Course2_ID);

        while(1) // check Course2 grade
        {
            printf("\nEnter Course2 grade\n");
            scanf("%d",&grade);
            if(isGrade_Ok(grade))
            {
                node->Course2_grade= grade;
                break;
            }

        }

        printf("\nEnter Course3 ID\n");
        scanf("%d",&node->Course3_ID);

        while(1) // check Course3 grade
        {
            printf("\nEnter Course3 grade\n");
            scanf("%d",&grade);
            if(isGrade_Ok(grade))
            {
                node->Course3_grade= grade;
                break;
            }

        }

        count++; // increase count of students
        node->next=NULL; // in linked list last position's next= null

        if(head==NULL) // if in first position put data
        {
            head=node;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)  // else put data in last position
            {
                temp=temp->next; // move to next position to check
            }
        temp->next=node; // store data
        }
        store_all_id_to_List(); // store all ids
        return true; //Added Successfully
    }
    else // if not successfull
    {
        return false;
    }
}


 void SDB_DeletEntry (uint32 id)
//Description: delete the student data with the given id.
{
    student* current_position=head;//
    student* previous_position=head;// both starting position = start(head)

    if(SDB_IsIdExist(id))// check id id exists to delete
    {
        while(current_position!=NULL) // loop to search for id to and get previous position in linked list
    {
        if(current_position->Student_ID==id) // check id
        {
            if(current_position==head) // check if it has head position
            {
                head=head->next; // give head position to next student
                free(current_position); // delete the wanted
                printf("\nDeleted Successfully\n");
                count--;// decrease count of students
                store_all_id_to_List(); // store all ids after deletion
                return; // finish
            }
            else
            {
                previous_position->next=current_position->next; // give current position to previous student
                free(current_position); // delete the wanted
                printf("\nDeleted Successfully\n");
                count--;// decrease count of students
                store_all_id_to_List(); // store all ids after deletion
                return; // finish
            }
        }

        else   // move all positions to its next to check next
        {
            previous_position=current_position;
            current_position=current_position->next;
        }
    }
    }

}

 bool SDB_ReadEntry (uint32 id)
//Description: print the data of the user by searching on his data by the given id
//Return: return 1 if the data is existed return 0 if this id not your database.
 {
     if(SDB_IsIdExist(id))// check if realy exists then print
     {
        printf("\nStudent ID = %d \n",temp->Student_ID);
        printf("Student year = %d \n",temp->Student_year);
        printf("Course1 ID = %d \n",temp->Course1_ID);
        printf("Course1 grade = %d \n",temp->Course1_grade);
        printf("Course2 ID = %d \n",temp->Course2_ID);
        printf("Course2 grade = %d \n",temp->Course2_grade);
        printf("Course3 ID = %d \n",temp->Course3_ID);
        printf("Course3 grade = %d \n",temp->Course3_grade);

        return true; // data exists
     }
     else
     {
         return false; //data does'nt exist
     }
 }

 void SDB_GetList (uint8 * count, uint32 * list) //using pointers
//Description: it gets the number of ids in the
//count and the list of all ids in list array that’s you get his base address.
 {
     if(count>0) // check if database is not empty
     {
         printf("\nList of Students id = {");
         uint32 i;
         for( i=0 ; i<count ; i++) // loop to print id list
           {
               printf(" %d"  , *(list +i) );
               if(i<count-1)
               {
                   printf(",");
               }
           }
         printf(" }\n");
     }
 }

 bool SDB_IsIdExist (uint32 id)
//Description: Checks if the given id realy is Exists
//Return: return 1 if the id is existed and return 0 if the id not found.
{
    temp=head;
    if(head!=NULL) // check id database is not empty
    {
        while(temp!=NULL) //loop and check if not reached last position
      {
        if(temp->Student_ID == id) // check id
        {
            printf("\nId Exists\n");
            return true; // found
        }
        else
        {
            temp=temp->next;
        }

        if(temp==NULL)
        {
            printf("\nId Not Found\n");
            return false; // not found
        }
      }
    }
    else
    {
        printf("\nId Not Found\n");
        return false; // not found
    }
}


