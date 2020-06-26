#include<stdio.h>
#define capacity 5
int front=0,rear=-1,queue[capacity];
int main()
{
	int ch,ele;
	while(1)
	{
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the elemnt:");
				scanf("%d",&ele);
				enque(ele);
				break;
			case 2:dque();
				break;
			case 3:display();
				break;
			case 4:
				exit(0);
			default:printf("\nEnter proper choice");
		}
	}
}
void enque(int ele)
{
	if(full())
	{
		printf("\nQueue is full");
	}
	else
	{
		rear++;
		queue[rear]=ele;
	}
}
int full()
{
	if(rear==capacity-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void dque()
{
	if(empty())
	{
		printf("\nQueue is empty");
	}
	else
	{
		int i;
		printf("\n deleted item is:%d",queue[front]);
		for(i=front;i<=rear;i++)
		{
		queue[i]=queue[i+1];
		
		}
		
	}
}
int empty()
{
	if(rear==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void display()
{
	if(empty())
	{
		printf("\n queue is empty");
	}
	else
	{
		int i;
		printf("\nQueue is:");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}
