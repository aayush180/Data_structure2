#include<stdio.H>
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

void Display(struct Node *p)
{
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
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

void InsertNode(struct Node *p,int index,int data)
{
    struct Node*t;

     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=data;

     if(index < 0 || index > Count(p))
     {
         return;
     }
     else
       {
         if(index == 0)
         {
          t->next=first;
          first=t;
         }
         else if(index > 0)
         {
             for(int i=0;i<index-1;i++)
             {
                 p=p->next;
             }
             t->next=p->next;
             p->next=t;
         }
        }
}

// Insert At Last Position
void InsertLast(struct Node *p,int data)
{
    struct Node *t,*last;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;

    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}

int main(){
    int A[]={3,5,7,9,11};
    CreateNode(A,5);
    InsertLast(first,13);
    Display(first);
   /* InsertNode(first,5,13);
    printf("\n");
    Display(first); */
}