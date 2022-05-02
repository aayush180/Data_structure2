#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
// Finding Middle Of Linked List By Slow And Fast Pointers 
int  Middle(struct Node *p)
{
    struct Node*q=p;

    while(q){
        q=q->next;
        if(q){
            p=p->next;
            q=q->next;
        }
    }
    return p->data;
}

void Display(struct Node *root)
{
    while(root != NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}

void RDisplay(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        RDisplay(root->next);
    }
}

int main()
{           
    int A[]={3,5,7,9,11,13,15};
    Create(A,7);
    
    printf("%d ",Middle(first));
}