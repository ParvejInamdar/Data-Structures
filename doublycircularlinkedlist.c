#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *root=NULL;
void display();
void pushf();
void pushb();
void pushl();
int length();
void deletef();
void deletel();
void deleteb();
void reverse();
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.Insert_First");
		printf("\n2.Insert_Between");
		printf("\n3.Insert_Last");
		printf("\n4.Display");
		printf("\n5.Length");
		printf("\n6.Delete_First");
		printf("\n7.Delete_Between");
		printf("\n8.Delete_Last");
		printf("\n9.Reverse_List");
		printf("\n10.Exit");
		printf("\nEnter Your Choice :  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				pushf();
				break;
			case 2:
				pushb();
				break;
			case 3:
				pushl();
				break;
			case 4:
				display();
				break;
			case 5:
				x=length();
				printf("\nLength of the List : %d",x);
				break;
			case 6:
				deletef();
				break;
			case 7:
				deleteb();
				break;
			case 8:
				deletel();
				break;
			case 9:
				reverse();
				break;
			case 10:
				exit(0);
			default:
				printf("\nEnter valid choice");
		}
	}
}
void pushf()
{
	struct node *temp,*p,*q;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		temp->next=root;
	}
	else
	{
		q=root;
		while(q->next!=root)
		{
			q=q->next;
		}
		p=root;
		temp->next=p;
		root=temp;
		p->prev=temp;
		q->next=root;
	}
}
void pushl()
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		temp->next=root;
	}
	else
	{
		p=root;
		while(p->next!=root)
		{
			p=p->next;
		}
		temp->prev=p;
		p->next=temp;
		temp->next=root;
	}
}
void display()
{
	struct node *temp;
	temp=root;
	while(temp->next!=root)
	{
		printf("\t%d-->",temp->data);
		temp=temp->next;
	}
	printf("\t%d-->",temp->data);
}
void pushb()
{
	struct node *temp,*p,*q;
	int pos,cpos=0,x,y=0;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->prev=NULL;
	x=length();
	printf("\nEnter the position to add node : ");
	scanf("%d",&pos);
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else if(y<x)
	{
		p=root;
		q=root;
		while(cpos!=pos)
		{
			cpos++;
			p=p->next;
			q=q->next;
		}
		q=q->next;
		temp->next=q;
		p->next=temp;
		q->prev=temp;
		temp->prev=p;
	}
	else
	{
		printf("\nEnter valid location");
	}
}
int length()
{
	int count=0;
	struct node *temp;
	temp=root;
	if(root==NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		while(temp->next!=root)
		{
			count++;
			temp=temp->next;
		}
		return count+1;
	}
}
void deletef()
{
	struct node *temp,*p;
	temp=root;
	p=root;
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(p->next!=root)
		{
			p=p->next;
		}
		root=temp->next;
		p->next=root;
	}
}
void deletel()
{
	struct node *temp;
	temp=root;
	while(temp->next->next!=root)
	{
		temp=temp->next;
	}
	temp->next=root;
	
}
void deleteb()
{
	int pos,cpos=0,x,y=0;
	struct node *temp,*p;
	temp=root;
	p=root;
	x=length();
	printf("\nEnter the node position to delete node : ");
	scanf("%d",&pos);
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else if(y<x)
	{
		while(cpos!=pos)
		{
			cpos++;
			temp=temp->next;
			p=p->next;
		}
		p=p->next;
		temp=temp->prev;
		temp->next=p;
		p->prev=temp;
	}
}
void reverse()
{
	struct node *temp,*p;
	temp=root;
	p=root;
	while(p->next!=root)
	{
		p=p->next;
	}
	printf("\nReverse of List is : ");
	while(p->prev!=NULL)
	{
		printf("\t%d-->",p->data);
		p=p->prev;
	}
	printf("\t%d-->",p->data);
}
