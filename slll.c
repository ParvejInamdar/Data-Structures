#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void insertf();
void insertl();
void display();
void length();
void insertb();
void deletef();
void deletel();
void deleteb();
void search();
struct node* root;
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.InsertFirst");
		printf("\n2.InsertLast");
		printf("\n3.Insertbetween");
		printf("\n4.Display");
		printf("\n5.Length");
		printf("\n6.deletef");
		printf("\n7.deletel");
		printf("\n8.deleteb");
		printf("\n9.Search");
		printf("\n10.Exit");
		printf("\nEnter your choice : ");
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
				length();
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
				search();
				break;
			case 10:
				exit(0);
			default:
				printf("\nEnter valid input");
		}
	}
}
void insertf()
{
	struct node* temp;
	struct node* addr;
	addr=root;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		root=temp;
		temp->next=addr;
	}
}
void insertl()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("\nEnter the data: ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
void display()
{
	struct node *p;
	p=root;
	printf("\nElements are:");
	while(p!=NULL)
	{
		printf("%d-->",p->data);
		p=p->next;
	}
}
void length()
{
	struct node *p;
	p=root;
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	printf("\nLength of the list is :%d",cnt);
}
void insertb()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		temp=root;
	}
	else
	{
		int pos,cpos;
		struct node* in;
		struct node* add;
		add=root;
		in=root;
		cpos=1;
		printf("\nEnter teh position to insert node after that position: ");
		scanf("%d",&pos);
		while(cpos!=pos)
		{
			cpos++;
			in=in->next;
			add=add->next;
		}
		temp->next=add->next;
		in->next=temp;		
	}
}
void deletef()
{
	struct node* temp;
	temp=root;
	if(root==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		root=temp->next;
		printf("\nFirst Node deleted");
	}
}
void deletel()
{
	if(root==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		struct node *temp;
		temp=root;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NULL;
	}
}
void deleteb()
{
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		int pos,cpos;
		struct node *temp;
		struct node *p;
		temp=root;
		p=root;
		cpos=1;
		printf("\nEnter the node position to delete next node:");
		scanf("%d",&pos);
		while(cpos!=pos)
		{
			p=p->next;
			temp=temp->next;
			cpos++;
		}
		p=p->next;
		temp->next=p->next;
	}
}
void search()
{
	int n;
	printf("\n Enter the data to serach : ");
	scanf("%d",&n);
	if(root==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		int ele;
		struct node* temp;
		temp=root;
		while(temp->data!=n)
		{
			temp=temp->next;
			ele=temp->data;
		}
		if(ele==n)
		{
			printf("\nElement found");
		}
		else
		{
			printf("\nElement not found");
		}
	}
}
