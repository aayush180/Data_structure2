#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void CreateNode(int A[],int n)
{
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int Count(struct Node *p)
{
    int count=0;

    while(p != NULL){
        count++;
        p=p->next;
    }
    return count;
}

void Display(struct Node *p)
{
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void Reverse1(struct Node *p)
{
    int *arr,i=0;
    struct Node*q;
    arr=(int *)malloc(Count(p)*sizeof(int));
    q=p;

    while(q != NULL)
    {
        arr[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;

    while(q != NULL)
    {
        q->data=arr[i--];
        q=q->next;
    }

}

void Reverse2(struct Node *p){
    struct Node *q=NULL,*r=NULL;

    while(p != NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

// Recersive Function For Reversing Linked List
void RReverse(struct Node *q,struct Node *p){
    if(p != NULL){
        RReverse(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

int main(){
    int A[]={2,5,7,9,11};
    CreateNode(A,5);
    Display(first);
    printf("\nAfter Reversing\n");
    
    RReverse(NULL,first);
    Display(first);
}
