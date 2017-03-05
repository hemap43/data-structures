/* write a function insert_beg to insert an element at begining of linked list*/

#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int);
struct node *add_beg(struct node *,int);
void display(struct node *);
struct node
{
	int val;
	struct node *next;
};
int main()
{
	struct node *head;
	int data,data1;
	printf("Enter the value data:\n");
	scanf("%d",&data);
	head=new_node(head,data);
	printf("header=%p\n",head);
	printf("Enter the value data1:\n");
	scanf("%d",&data1);
	head=add_beg(head,data1);
	printf("header=%p\n",head);
	display(head);
	
}

struct node *new_node(struct node *head,int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("%p\n",temp);
	temp->val=x;
	temp->next=NULL;
	head=temp;
	return head;
}
struct node *add_beg(struct node *head,int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("%p\n",temp);
	temp->val=x;
	temp->next=head;
	head=temp;
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
	
	

