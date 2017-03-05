/*write a function insert_after() to insert an element after search() function*/

#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int,int);
struct node *insert_after(struct node *,int,int);
void display(struct node *);
struct node
{
	int val;
	struct node *next;
};
int main()
{
	struct node *head = NULL;
	int data,search_data,insert_data,num;
	printf("Enter number of nodes to be create:\n");
	scanf("%d",&num);
	printf("Enter the value of first node:\n");
	scanf("%d",&data);
	head=new_node(head,data,num);
	printf("header=%p\n",head);
	printf("Enter the value to be searched:\n");
	scanf("%d",&search_data);
	printf("Enter the value to be inserted:\n");
	scanf("%d",&insert_data);
	head=insert_after(head,search_data,insert_data);
	printf("head=%p\n",head);
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
struct node *insert_after(struct node *head,int search_data,int insert_data)
{
	struct node *temp,*prev;
	prev=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	 {
	 	return head;
	 }
	 temp=head;
	//searching loop:
	while(temp->val!=search_data && temp->next!=NULL)
	 {
	 	temp=temp->next;
	 }
	 //insertion of new data:
	 if(temp->val==search_data)
	  {
	  	prev->val=insert_data;
	  	prev->next=temp->next;
	  	temp->next=prev;
	  	return head;
	  }
	  else 
	  {
	  	temp->next=prev;
	  	prev->val=insert_data;
	  	prev->next=NULL;
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
	
	
	
	
	
	
	
	
	
	
	
	
