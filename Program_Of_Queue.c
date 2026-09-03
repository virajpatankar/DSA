#include<stdio.h>
#include<conio.h>

#define Max 5

int Queue[Max];
int front;
int rear;

int is_full()
{


     if(rear == Max)
     {

         return 1;
     }
     return 0;

}

int is_empty()
{

     if(rear == front)
     {

        return 1;

     }
     return 0;
}

void insert(int No)
{

     if(is_full())
     {

         printf("\n Queue is already full... Can't Insert New Element...");

     }
     else
     {

         Queue[rear] = No;
         rear ++;

     }

}

void Delete(int No)
{

    if(is_empty())
    {

       printf("\n Queue is Already Empty...Can't Delete The Element");

    }
    else
    {

        printf("\n Deleted Element from Queue is = %d.",Queue[front]);

        Queue[front] = 0;
        front ++;

    }

}

void Display_Queue()
{

     if(is_empty())
     {

        printf("\n Queue is Already Empty ... Can't Display The Element");

     }
     else
     {

        int i = 0;
        printf("\n Current Elements in Queue are =>\n ");

        for(i = front; i < rear; i++);
        {

           printf("\t\t|%4d|\n",Queue[i]);

        }

     }

}

int Count_Queue_Elements()

{
    return rear - front;
}

int Search_Queue_Element(int No)
{

      if(is_empty())
      {
          printf("\n Queue is Already Empty... Can't Display The Element");
      }
      else
      {

          int cnt = front;

          while(cnt < rear)
          {

              if(Queue[cnt] == No)
              {

                  return cnt-front + 1;
              }
              cnt++;
          }
      }
      return -1;
}

int main()
{


       int ret = 0;

       insert(21);
       insert(55);
       insert(12);
       insert(666);

       getche();
       Display_Queue();

       getche();
       printf("\n\n Number of Elements in Queue are = %d.\n",Count_Queue_Elements());

       Delete(21);
       Delete(12);
       Delete(55);
       Delete(666);

       getche();

       ret = Search_Queue_Element(956);

       if(ret < 0)
       {

           printf("\n Number Not Found...");
       }
       else
       {

           printf("\n Given Number Found at Location %d.",ret);

       }

       printf("\n\nNumber of Element in Queue are = %d.\n",Count_Queue_Elements());

       Display_Queue();

       insert(75);
       insert(56);
       insert(121);
       insert(5485);

       Display_Queue();

       ret = Search_Queue_Element(56);

       if(ret < 0)
       {

           printf("\n No Not Found...");
       }
       else
       {

           printf("\n Given Number Found at Location %d.",ret);
       }

       printf("\n\nNumber of Elements in Queue are = %d.\n",Count_Queue_Elements());

       getch();

       Display_Queue();

       return 0;



}


