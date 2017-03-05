/*write a function delete_beg() & delete_end() to delete element from linked list.*/

#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int,int);
struct node *delete(struct node *,int);
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
	printf("Enter the data to be delete:\n");
	scanf("%d",&data1);
	head=delete(head,data1);
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
struct node *delete(struct node *head,int x)
{
	struct node *temp,*prev;
	if(head==NULL)
	 {
	 	printf("no linked list:\n");
	 	return head;
	 }
	 //checking first deletion condition:
	 if(head->val==x)
	 {
	 	temp=head;
	 	head=head->next;
	 	temp->next=NULL;
	 	free(temp);
	 	return head;
	 }
	 //checking middle deletion condition:
	 temp=head;
	 while(temp->val!=x && temp->next!=NULL)
	  {
	  	prev=temp;
	  	temp=temp->next;
	  }
	  if(temp->val==x)
	  {
	  	prev->next=temp->next;
	  	temp->next=NULL;
	  	free(temp);
	  	return head;
	  }
	  //checking last deletion condition:
	  else 
	  {
	  	printf("Element not found:\n");
	  	return head;
	  }
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
	  		 

