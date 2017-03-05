/*write a function print_reverse() for printing the elements of a linked list in the REVERSE ORDER*/

#include<stdio.h>
#include<stdlib.h>
struct node *new_node(struct node *,int,int);
struct node *reverse(struct node *,int);
void print_list(struct node *);
//void display(struct node *);
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
	head=reverse(head,num);
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
        do
        {
                printf("0x%p=%d\n",head,head->val);
                head=head->next;
        }while(head->next!=NULL)
        
}


//function for reversing the elements of nodes:

struct node *reverse(struct node *head,int num)
{
  struct node *temp,*last;
  int *prev[num-1],index,i,j,data;
  temp=head;
  for(index=0,last=temp;((index<num)&&(last->next!=NULL));index++)
  {
          prev[index]=last;
          last=last->next;
  }
  for(i=0,j=num-2;i<j;i++,j--)
  {
          data=temp->val;
          temp->val=last->val;
          last->val=data;
          temp=temp->next;
          last=prev[j];
  }
  return head;
}
/*void display(struct node *head)
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
}*/	
	
	
	
	
	
	
	
	
	
	
	
	
