#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void CreateNode(int A[],int n)
{
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void CreateNode2(int B[],int n)
{
    struct Node *t,*last;

    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=B[0];
    second->next=NULL;
    last=second;

    for(int i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Concate(struct Node*p,struct Node*q){
    third=p;

    while(p->next != NULL){
       p=p->next;
    }
    p->next=q;
}

void Merge(struct Node*p,struct Node*q)
{
    struct Node*last;

    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
       third=last=q;
       q=q->next;
       third->next=NULL;
    }

    while(p != NULL && q != NULL)
    {
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p != NULL){
        last->next=p;
    }
    if(q != NULL){
        last->next=q;
    }
}

void Display(struct Node*p){
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={1,3,5,7,9};
    int B[]={2,4,6,8,10};
    
    CreateNode(A,5);
    CreateNode2(B,5);

    Merge(first,second);
    Display(third);

}