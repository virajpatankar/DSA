#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};


/* ================= INSERT FIRST ================= */

void Insert_First(struct Node **First, int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*)malloc(sizeof(struct Node));

    if(NewN == NULL)
    {
        printf("\nMemory Allocation Failed!!!");
        return;
    }

    NewN->Data = No;
    NewN->Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        NewN->Next = *First;
        *First = NewN;
    }

    printf("\n%d Element Inserted at First Position Successfully", No);

    return;
}


/* ================= INSERT LAST ================= */

void Insert_Last(struct Node **First, int No)
{
    struct Node *NewN = NULL;
    struct Node *Temp = NULL;

    NewN = (struct Node*)malloc(sizeof(struct Node));

    if(NewN == NULL)
    {
        printf("\nMemory Allocation Failed!!!");
        return;
    }

    NewN->Data = No;
    NewN->Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        Temp = *First;

        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }

        Temp->Next = NewN;
    }

    printf("\n%d Element Inserted at Last Position Successfully", No);
}


/* ================= DISPLAY ================= */

void Display_LL(struct Node *First)
{
    if(First == NULL)
    {
        printf("\nGiven Linked List is Already Empty!!!");
    }
    else
    {
        printf("\n\nElements in Given Linked List are =>\n\n");

        while(First != NULL)
        {
            printf("| %d | -> ", First->Data);
            First = First->Next;
        }

        printf("NULL");
    }
}


/* ================= COUNT NODES ================= */

int Count_LL_Nodes(struct Node *First)
{
    int Cnt = 0;

    while(First != NULL)
    {
        Cnt++;
        First = First->Next;
    }

    return Cnt;
}


/* ================= INSERT AT POSITION ================= */

void Insert_At_Position(struct Node **First, int Pos, int Val)
{
    int Ele_Cnt = Count_LL_Nodes(*First);

    struct Node *NewN = NULL;
    struct Node *Temp = NULL;

    if(Pos <= 0 || Pos > Ele_Cnt + 1)
    {
        printf("\nInvalid Position To Insert!!!");
        return;
    }

    if(Pos == 1)
    {
        Insert_First(First, Val);
    }
    else if(Pos == Ele_Cnt + 1)
    {
        Insert_Last(First, Val);
    }
    else
    {
        NewN = (struct Node*)malloc(sizeof(struct Node));

        if(NewN == NULL)
        {
            printf("\nMemory Allocation Failed!!!");
            return;
        }

        NewN->Data = Val;
        NewN->Next = NULL;

        Temp = *First;

        while(Pos > 2)
        {
            Temp = Temp->Next;
            Pos--;
        }

        NewN->Next = Temp->Next;
        Temp->Next = NewN;

        printf("\n%d Element Inserted at Given Position Successfully", Val);
    }
}


/* ================= DELETE FIRST ================= */

void Delete_First(struct Node **First)
{
    struct Node *Temp = NULL;

    if(*First == NULL)
    {
        printf("\nLinked List is Already Empty!!!");
        return;
    }

    Temp = *First;

    *First = (*First)->Next;

    printf("\n%d Element Deleted from First Position Successfully",
           Temp->Data);

    free(Temp);
}


/* ================= DELETE LAST ================= */

void Delete_Last(struct Node **First)
{
    struct Node *Temp = NULL;

    if(*First == NULL)
    {
        printf("\nLinked List is Already Empty!!!");
        return;
    }

    /* Only one node */
    if((*First)->Next == NULL)
    {
        printf("\n%d Element Deleted from Last Position Successfully",
               (*First)->Data);

        free(*First);
        *First = NULL;

        return;
    }

    Temp = *First;

    while(Temp->Next->Next != NULL)
    {
        Temp = Temp->Next;
    }

    printf("\n%d Element Deleted from Last Position Successfully",
           Temp->Next->Data);

    free(Temp->Next);

    Temp->Next = NULL;
}


/* ================= DELETE AT POSITION ================= */

void Delete_At_Position(struct Node **First, int Pos)
{
    int Ele_Cnt = Count_LL_Nodes(*First);

    struct Node *Temp = NULL;
    struct Node *DeleteN = NULL;

    if(*First == NULL)
    {
        printf("\nLinked List is Already Empty!!!");
        return;
    }

    if(Pos <= 0 || Pos > Ele_Cnt)
    {
        printf("\nInvalid Position To Delete!!!");
        return;
    }

    if(Pos == 1)
    {
        Delete_First(First);
        return;
    }

    if(Pos == Ele_Cnt)
    {
        Delete_Last(First);
        return;
    }

    Temp = *First;

    while(Pos > 2)
    {
        Temp = Temp->Next;
        Pos--;
    }

    DeleteN = Temp->Next;

    Temp->Next = DeleteN->Next;

    printf("\n%d Element Deleted from Given Position Successfully",
           DeleteN->Data);

    free(DeleteN);
}


/* ================= MAIN ================= */

int main()
{
    struct Node *Head = NULL;

    /* INSERT FIRST */
    Insert_First(&Head, 10);

    /* INSERT LAST */
    Insert_Last(&Head, 20);

    Insert_First(&Head, 30);

    Insert_Last(&Head, 40);

    Insert_First(&Head, 50);

    Insert_Last(&Head, 60);


    /* DISPLAY */
    Display_LL(Head);

    getch();


    /* INSERT AT POSITION */

    Insert_At_Position(&Head, 0, 55);     // Invalid

    Insert_At_Position(&Head, 1, 15);

    Insert_At_Position(&Head, 2, 41);

    Insert_At_Position(&Head, 5, 101);

    Insert_At_Position(&Head, 1, 21);

    Insert_At_Position(&Head, 3, 884);


    /* DISPLAY AFTER INSERT */

    Display_LL(Head);

    getch();


    /* COUNT */

    printf("\n\nTotal Number of Nodes = %d",
           Count_LL_Nodes(Head));

    getch();


    /* DELETE FIRST */

    Delete_First(&Head);

    Display_LL(Head);

    getch();


    /* DELETE LAST */

    Delete_Last(&Head);

    Display_LL(Head);

    getch();


    /* DELETE AT POSITION */

    Delete_At_Position(&Head, 3);

    Display_LL(Head);

    getch();


    /* CLEAR SCREEN */

    system("cls");

    Display_LL(Head);

    getch();


    return 0;
}
