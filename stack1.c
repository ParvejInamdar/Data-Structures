#include<stdio.h>
#define capacity 5
int arr[capacity],top=-1;
void push(int);
int pop();
int full();
int empty();
void peek();
void display();
int main()
{
	int ch,ele,x;
	while(1)
	{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the elment to push:");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:
				x=pop();
				printf("\ntop is : %d",x);
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("\nEnter valid input");
				break;
		}
	}
}
void push(int ele)
{
	if(full())
	{
		printf("\nStack is full");
	}
	else
	{
		top++;
		arr[top]=ele;
		printf("\nElement inserted sucessfully:%d",arr[top]);
	}
}
int full()
{
	if(top==capacity-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop()
{
	if(empty())
	{
		printf("\nStack is empty");
	}
	else
	{
		top--;
		printf("\ndeleted sucessfully");
		return arr[top];
	}
}
int empty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void peek()
{
	if(empty())
	{
		printf("\nstack is empty");
	}
	else
	{
		printf("\ntop element iis : %d",arr[top]);
	}
}
void display()
{
	if(empty())
	{
		printf("\nstack is empty");
	}
	else
	{
		int i;
		printf("\nstack element is:");
		for(i=0;i<=top;i++)
		{
			printf("%d\t",arr[i]);
		}
	}
}
