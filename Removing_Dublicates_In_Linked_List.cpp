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

    for(int i=0;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next;

    while(q)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void Display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main()
{
    int A[]={2,4,4,4,6,8,9,9};
    CreateNode(A,8);
    Display(first);
    printf("\n After Deletion \n");
    RemoveDuplicate(first);
    Display(first);
}