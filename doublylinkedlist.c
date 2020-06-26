#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* prev;
	struct node* next;
};
struct node *root=NULL;
void pushf();
void pushb();
void pushl();
void display();
void deletef();
void deletel();
void deleteb();
int length();
void reverse();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert_First");
		printf("\n2.Insert_between");
		printf("\n3.Insert_Last");
		printf("\n4.Display");
		printf("\n5.Delete_First");
		printf("\n6.Delete_Last");
		printf("\n7.Delete_between");
		printf("\n8.Length");
		printf("\n9.Reverse_List");
		printf("\n10.Exit");
		printf("\nEnter your choice : ");
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
				deletef();
				break;
			case 6:
				deletel();
				break;
			case 7:
				deleteb();
				break;
			case 8:
				length();
				break;
			case 9:
				reverse();
				break;
			case 10:
				exit(0);
			default:
				printf("\nEnter valid choice.");
				break;
		}
	}
}
void pushf()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		root=temp;
		temp->next=p;
		p->prev=temp;
	}
}
void pushb()
{
	int pos,cpos=0;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nEnter the position to add node : ");
	scanf("%d",&pos);
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		printf("\nList is empty therefor your node is added to first position.");
	}
	else
	{
		struct node *p;
		struct node *q;
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
}
void pushl()
{
	struct node* temp;
	struct node* p;
	p=root;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
	}
	
}
void display()
{
	struct node *temp;
	temp=root;
	while(temp!=NULL)
	{
		printf("\t%d-->",temp->data);
		temp=temp->next;
	}
}
void deletef()
{
	struct node* q;
	q=root;
	q=q->next;
	root=q;
	q->prev=NULL;
}
void deletel()
{
	struct node* temp;
	temp=root;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=NULL;
}
void deleteb()
{
	struct node *p;
	struct node* q;
	q=root;
	p=root;
	int pos,cpos=0;
	printf("\nEnter the  position to delete node : ");
	scanf("%d",&pos);
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(cpos!=pos)
		{
			cpos++;
			p=p->next;
			q=q->next;
		}
		q=q->next->next;
		p->next=q;
		q->prev=p;
	}
}
int length()
{
	struct node* temp;
	temp=root;
	int cnt=0;
	if(root==NULL)
	{
		printf("\nList is Empty!!!!!!!!!");
		return 0;
	}
	else
	{
		while(temp!=NULL)
		{
			cnt++;
			temp=temp->next;
		}
		printf("\nLength of the list is : %d",cnt);
		return cnt;	
	}
}
void reverse()
{
	struct node* temp;
	temp=root;
	if(root==NULL)
	{
		printf("\nList is empty!!!");
	}
	else
	{
		struct node *q;
		q=root;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp->prev!=NULL)
		{
			printf("\t%d-->",temp->data);
			temp=temp->prev;
		}
		printf("\t%d-->",temp->data);
	}
}
