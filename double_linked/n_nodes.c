/*create n nodes in doubly linked list*/
#include<stdio.h>
#include<stdlib.h>
struct dlist *create(struct dlist *,int);
void display(struct dlist *);
struct dlist
{
    int data;
    struct dlist *prev;
    struct dlist *next;
};
int main()
{
    struct dlist *head;
    head=NULL;
    int n;
    printf("Enter number nodes to be created:\n");
    scanf("%d",&n);
    head=create(head,n);
    display(head);
}
struct dlist *create(struct dlist *head,int n)
{
    int val,node;
    struct dlist *temp=NULL,*newnode;
    /*head=temp;
    newnode=(struct dlist *)malloc(sizeof(struct dlist));
    printf("Enter data for 1 node:\n");
    scanf("%d",&val);
    newnode->data=val;
    newnode->prev=temp;
    newnode->next=NULL;
    temp=newnode;*/
    for(node=1;node<=n;node++)
    {
        newnode=(struct dlist *)malloc(sizeof(struct dlist));
        printf("Enter data for %d node\n",node);
        scanf("%d",&val);
        newnode->data=val;
        newnode->prev=temp;
        newnode->next=NULL;
        if(temp!=NULL)
        {
            temp->next=newnode;
        }
        else
        {
            head=newnode;
        }
        temp=newnode;
    }
    return head;
}
void display(struct dlist *head)
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
	
	
	
	
