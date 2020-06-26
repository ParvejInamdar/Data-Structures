#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void insertf();
void insertl();
void insertb();
int length();
void display();
void deletef();
void deletel();
void deleteb();
struct node *root=NULL;
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.Insert_first");
		printf("\n2.Insert_Last");
		printf("\n3.Insert_Between");
		printf("\n4.Display");
		printf("\n5.Length");
		printf("\n6.Delete_First");
		printf("\n7.Delete_Last");
		printf("\n8.Delete_Last");
		printf("\n9.Exit");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertf();
				break;
			case 2:
				insertl();
				break;
			case 3:
				insertb();
				break;
			case 4:
				display();
				break;
			case 5:
				x=length();
				printf("\nLength is : %d",x);
				break;
			case 6:
				deletef();
				break;
			case 7:
				deletel();
				break;
			case 8:
				deleteb();
				break;
			case 9:
				exit(0);
			default:
				printf("\nEnter valid choice");
		}
	}
}
void insertl()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		temp->next=root;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->next!=root)
		{
			p=p->next;
		}
		p->next=temp;
		temp->next=root;
	}
}
int length()
{
	struct node* p;
	p=root;
	int cnt=0;
	while(p->next!=root)
	{
		cnt++;
		p=p->next;
	}
	return cnt+1;
}
void display()
{
	int y,x=0;
	struct node* p,*q;
	p=root;
	q=root;
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(q->next!=root)
		{
			q=q->next;
		}
		q=q->next;
		while(p->next!=q)
		{
			printf("\t%d-->",p->data);
			p=p->next;
		}
		printf("\t%d-->",p->data);	
		}
}
void insertf()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		temp->next=root;
	}
	else
	{
		struct node *p,*q;
		p=root;
		q=root;
		while(q->next!=root)
		{
			q=q->next;
		}
		temp->next=p;
		root=temp;
		q->next=root;
	}
}
void insertb()
{
	int x,pos,cpos=0;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	x=length();
	printf("\nEnter the position to add node : ");
	scanf("%d",&pos);
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		printf("\nList is empty therefore we added element at first Position");
	}
	else if(pos<x)
	{
		struct node *p,*q;
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
		
	}	
	else
	{
		printf("\nEnter valid choice");
	}
}
void deletef()
{
	struct node *temp,*p;
	temp=root;
	p=root;
	if(root==NULL)
	{
		printf("\nList is Emppty");
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
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(temp->next->next!=root)
		{
			temp=temp->next;
		}
		temp->next->next=NULL;
		temp->next=root;	
	}
	
}
void deleteb()
{
	int pos,cpos,x,y=0;
	struct node *temp,*p;
	temp=root;
	p=root;
	printf("\nEnter position to Delete : ");
	scanf("%d",&pos);
	x=length();
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
		p=p->next->next;
		temp->next=p;
	}
	else
	{
		printf("\nEnter the vlaid choice");
	}
}
