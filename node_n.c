/* creation of n nodes and add an element at the end*/

#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int,int);
struct node *add_end(struct node *,int);
void display(struct node *);
struct node
{
	int val;
	struct node *next;
};
int main()
{
	struct node *head;
	int data,data1,num;
	printf("Enter the value data:\n");
	scanf("%d",&data);
	printf("Enter number nodes to create:\n");
	scanf("%d",&num);
	head=new_node(head,data,num);
	printf("header=%p\n",head);
	printf("Enter the value data1:\n");
	scanf("%d",&data1);
	head=add_end(head,data1);
	printf("header=%p\n",head);
	display(head);
	
}

struct node *new_node(struct node *head,int x,int num)
{
	struct node *temp,*trev;
	int node,data;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("%p\n",temp);
	temp->val=x;
	temp->next=NULL;
	head=temp;
	trev=head;
	for(node=2;node<=num;node++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the value of data:\n");
		scanf("%d",&data);
		temp->val=data;
		trev->next=temp;
		trev=trev->next;
		temp->next=NULL;
	}
	return head;
}
struct node *add_end(struct node *head,int x)
{
	struct node *temp,*trev;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("%p\n",temp);
	temp->val=x;
	temp->next=NULL;
	trev=head;
	while(trev->next!=NULL)
	{
		trev=trev->next;
	}
	trev->next=temp;	
	return head;
}
void display(struct node *head)
{
	if(head==NULL)
	{
		return; 
	}
	while(head->next!=NULL)
	{
		printf("%d\n",head->val);
		head=head->next;
	}
	printf("%d\n",head->val);
}
	
	

