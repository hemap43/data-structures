/*intersection of two sorted linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node *create(struct node *,int);
struct node *intersect(struct node *,struct node *,struct node *);
void display(struct node *);
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    int num;
    printf("Enter number of nodes to be created in first linked list:L\n");
    scanf("%d",&num);
    head1=create(head1,num);
    printf("First linked list is:\n");
    display(head1);
    printf("Enter number of nodes to be created in second linked list:L\n");
    scanf("%d",&num);
    head2=create(head2,num);
    printf("Second linked list is:\n");
    display(head2);
    head3=intersect(head1,head2,head3);
    printf("The intersected linked list is:\n");
    display(head3);
    return 0;
}
struct node *create(struct node *head1,int num)
{
    struct node *temp=NULL,*newnode;
    int val,node;
    for(node=1;node<=num;node++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data for %d node\n",node);
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
         if(temp!=NULL)
        {
            temp->next=newnode;
        }
        else
        {
            head1=newnode;
        }
        temp=newnode;
    }
    return head1;
}
void display(struct node *head)
{
	if(head==NULL)
	{
		return; 
	}
	while(head->next!=NULL)
	{
		printf("0x%p=%d\n",head,head->data);
		head=head->next;
	}
	printf("0x%p=%d\n",head,head->data);
}
struct node *intersect(struct node *head1,struct node *head2,struct node *head3)
{
    struct node *node1=head1,*node2=head2,*node3=NULL,*newnode=NULL;
    while(node1!=NULL)
    {
        while(node2!=NULL)
        {
            if(node1->data==node2->data)
            {
                newnode=(struct node *)malloc(sizeof(struct node));
                newnode->data=node1->data;
                newnode->next=NULL;
                if(node3!=NULL)
                {
                    node3->next=newnode;
                }
                else
                {
                    head3=newnode;
                }
                node3=newnode;
                node1=node1->next;
                node2=node2->next;
                break;
                
            }
            else
            {
                if(node2->next==NULL)
                {
                    node2=head2;
                    node1=node1->next;
                    break;
                }
                else
                {
                    node2=node2->next;
                }
            }
        }
    }
    printf("no matching element found:\n");
    return head3;
   
}
	
