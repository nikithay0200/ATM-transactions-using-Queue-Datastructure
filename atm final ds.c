#include<stdio.h>
#define max 10
int deposit(int);
int withdraw();
void checkbalance();
int amount[max],front=0,rear=-1;
char opr[max];
void insert(char ,int);
void ministmt();
int tamount=0,wx,dx,x;
void main()
{
char ch='y';
int c,x,pin;
while (pin != 1520)

    {

      printf ("ENTER YOUR FOUR DIGIT PIN NUM:"); //User will Enter the Four Digit Pin Code

      scanf ("%d", &pin); // Reads OutPut

      if (pin != 1520) /// IF It is Not The COrrect Pin

      printf ("WRONG PASSWORD! TRY AGAIN\n");

    }
while(ch=='y')
{
printf("\n1:deposit cash\n2:withdraw cash\n3:check balance\n4:ministmt\n");
printf("enter your option");
scanf("%d",&c);
switch(c)
{
case 1:printf("\nenter the amount to deposit");
scanf("%d",&x);
dx=deposit(x);
insert('D',dx);
break;
case 2:
wx=withdraw();
insert('W',wx);
break;
case 3:printf("\nthe contents of the queue are\n");
checkbalance();
break;
case 4:ministmt();
break;
}
printf("\ndo u want to continue the transaction(y/n)");
fflush(stdin);
ch=getchar();
}
printf("\nThanks for using our ATM service");
}
int deposit(int x)
{
tamount=tamount+x;
return x;
}
int withdraw()

{
printf("\nenter the amount you need");
scanf("%d",&x);
if(x<=tamount)
{
printf("\nthe amount you withdrawn is %d",x);
tamount=tamount-x;
return x;
}
else
    printf("sorry,no sufficient balance");
return 0;
}
void checkbalance()
{
printf("balance is %d",tamount);
}
void insert(char s,int p)
{
    if(((rear==max-1)&&front==0)||((front==rear+1)&&(front!=0&&rear!=-1)))
        {
            front=(front+1)%max;
        }
        else
            {
             rear=(rear+1)%max;
             amount[rear]=p;
             opr[rear]=s;
            }
}
void ministmt()
{
    int i;
  if(front==0&&rear==-1)
    printf("\nno transactions");
  else if(front>rear)
  {
      for(i=front;i<max-1;i++)
        printf("\n%c %3d",opr[i],amount[i]);
  }
      else
      {
         for(i=front;i<=rear;i++)
                 printf("\n%c   %3d",opr[i],amount[i]);

    }


}
