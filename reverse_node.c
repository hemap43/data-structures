/*write a function reverse() to reverse a Linked list*/


#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int,int);
struct node *reverse_node(struct node *,int);
void print_list(struct node *);
struct node
{
	int val;
	struct node *next;
};
int main()
{
	struct node *head = NULL;
	int data,num;
	printf("Enter number of nodes to be create:\n");
	scanf("%d",&num);
	printf("Enter the value of first node:\n");
	scanf("%d",&data);
	head=new_node(head,data,num);
	printf("header=%p\n",head);
        print_list(head);
	head=reverse_node(head,num);
	printf("head=%p\n",head);
	print_list(head);
	
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

void print_list(struct node *head)
{
        if(head==NULL)
	{
		return; 
	}
        while(head->next!=NULL)
        {
                printf("0x%p=%d\n",head,head->val);
                head=head->next;
        }
        printf("0x%p=%d\n",head,head->val);
        
}


//function for reversing the elements of nodes:

struct node *reverse_node(struct node *head,int num)
{
  struct node *temp,*last;
  int *prev[num-1],index,j;
  temp=head;
  for(index=0,last=temp;((index<num)&&(last->next!=NULL));index++)
  {
          prev[index]=last;
          last=last->next;
  }
  head=last;
  temp->next=NULL;
  for(j=num-2;j>=0;j--)
  {
          last->next=prev[j];
          last=prev[j];
  }
  return head;
}
