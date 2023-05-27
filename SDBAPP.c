#include "SDB.h"
extern uint32 id;
extern uint8 count;
extern uint32 list[];
uint8 choice ;// choice to which function to use

void SDB_APP ()
//Description: it has a super loop it will make your project until the user chose to exit you
//will ask the user to choose between these options
{

    while(1) //super loop to make project running until the user choses to exit
    {

        printf("\n1. To add entry, enter 1 \n");
        printf("2. To get used size in database, enter 2 \n");
        printf("3. To read student data, enter 3 \n");
        printf("4. To get the list of all student IDs, enter 4 \n");
        printf("5. To check is ID is existed, enter 5 \n");
        printf("6. To delete student data, enter 6 \n");
        printf("7. To check is database is full, enter 7 \n");
        printf("8. To exit enter 0 \n \n");

        scanf("%d",&choice);
        //Then it will call the SDB_action
        SDB_action(choice);
    }
}

void SDB_action (uint8 choice)
//Description: it well takes the user choice and call the responding function for this choice.
{
    printf("\nyour choice is %d\n",choice);
    switch((uint32)choice)
    {
        case 1:
            if(SDB_AddEntry())
            {
                printf("\nAdded Successfully\n");
            }
            else
            {
                printf("\nERROR Adding data\n");
            }
            break;

        case 2:
            SDB_GetUsedSize();
            break;

        case 3:
            id=Enter_Id();
            if(SDB_ReadEntry( id ))//uint32 id
            {
                printf("\nRead Successfully\n");
            }
            else
            {
                printf("\nERROR Reading data\n");
            }
            break;

        case 4:
            SDB_GetList ( count, list );//uint8 * count  uint32 * list
            break;

        case 5:
            id=Enter_Id();
            SDB_IsIdExist ( id );//uint32 id
            break;

        case 6:
            id=Enter_Id();
            SDB_DeletEntry ( id );//uint32 id
            break;

        case 7:
            if(SDB_IsFull()!=true)
            {printf("\nDatabase is still not Full\n");}
            break;

        case 0:
            exit(1); // exit program
            break;

        default:
            printf("\ntry again\n\n");
            break;
    }
}
