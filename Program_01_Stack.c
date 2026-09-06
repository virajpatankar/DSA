#include<stdio.h>
#include<conio.h>

#define Max 5


          int Stack [Max];
          int Top = 0;

          int Is_Stack_Full()
          {

               if(Top == Max)
               {

                   return 1;
               }
               return 0;
          }

          int Is_Stack_Empty()
          {

              if(Top == 0)
              {

                  return 1;
              }
              return 0;
          }

          void push(int No)
          {
              if (Is_Stack_Full())
              {

                  printf ("\n Stack is already full... Can't insert new element...");

              }
              else
              {

                  Stack [Top] = No;
                  Top ++;
              }
              return;


          }

          void pop()
          {

              if (Is_Stack_Empty())
              {

                  printf("\n Stack is Already Empty SO We Can't Delete Any Element...");

              }
              else
              {

                  printf("\n Deleted Element From Stack is %d.",Stack [Top - 1]);
                  Stack[Top -1] = 0;
                  Top --;

              }
              return;


          }

          void Display_Stack()
          {

               if (Is_Stack_Empty())
               {

                   printf("\n Stack is Already Empty so we can't Display any Element...");
               }
               else
               {

                   int i = 0;
                   printf("\n Current Elements in Stack are => \n");
                   for (i = Top-1; i >=0; i--)
                   {

                       printf("\t\t|%4d|\n", Stack[i]);
                   }
               }
          }

          int Count_Stack_Elements()
{
            return Top;
}

int Search_Stack_Element(int No)
{
            if(Is_Stack_Empty())
            {
                printf("\n Stack is Already Empty So We Can't Search any element...");
            }
            else
            {
                int Cnt = 0;

                while(Cnt < Top)
                {
                    if(Stack[Cnt] == No)
                    {
                        return Cnt+1;
                    }
                    Cnt++;
                }
            }
            return -1;
}

int main()
{
    int ret = 0;

    push(21);
    push(55);
    push(12);


    getche();

    Display_Stack();

    getche();

    printf("\n\n Number of Elements in Stack are = %d.\n",Count_Stack_Elements());



    pop();
    pop();
    pop();
    pop();

    getche();

    ret = Search_Stack_Element(56);

    if(ret < 0)
    {

        printf("\n Number Not Found...");
    }

    else
    {

        printf("\n Given Number Found at Location %d.", ret);
    }


    printf("\n\n Number of Elements in Stack are = %d.\n",
           Count_Stack_Elements());

    Display_Stack();

    push(75);
    push(56);
    push(121);
    push(5485);

    Display_Stack();

    ret = Search_Stack_Element(56);

    if(ret < 0)
    {

        printf("\n No Not Found...");
    }

    else
    {

        printf("\n Given Number Found at Location %d.", ret);
    }


    printf("\n\n Number of Elements in Stack are = %d.\n",
           Count_Stack_Elements());

    getch();

    return 0;
}
