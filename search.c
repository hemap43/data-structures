/*write a function search() to search as element in linked list and return node address.Return NULL for failed search*/

#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int,int);
struct node *search(struct node *,int);
void display(struct node *);
struct node
{
	int val;
	struct node *next;
};
int main()
{
	struct node *head,*head1;
	int data,data1,num;
	printf("Enter number of nodes to be create:\n");
	scanf("%d",&num);
	printf("Enter the value of first node:\n");
	scanf("%d",&data);
	head=new_node(head,data,num);
	printf("header=%p\n",head);
	printf("Enter the value to be searched:\n");
	scanf("%d",&data1);
	head1=search(head,data1);
	printf("head1=%p\n",head1);
	display(head);
	
}

struct node *new_node(struct node *head,int x,int num)
{
	struct node *temp,*trev;
	int node,data;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("node address=%p\n",temp);
	temp->val=x;
	temp->next=NULL;
	head=temp;
	trev=head;
	for(node=2;node<=num;node++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("node address=%p\n",temp);
		printf("Enter the value of data:\n");
		scanf("%d",&data);
		temp->val=data;
		trev->next=temp;
		trev=trev->next;
		temp->next=NULL;
	}
	return head;
}
struct node *search(struct node *head,int x)
{
	struct node *temp;
	temp=head;
	/*if(head==NULL)
	 {
	 	return ;
	 }*/
	while(temp->val!=x && temp->next!=NULL)
	 {
	 	temp=temp->next;
	 }
	 if(temp->val==x)
	  {
	  	return temp;
	  }
	  else 
	   return NULL;
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
	
	
	
	
	
	
	
	
	
	
	
	
