#include<stdio.h>
#include<stdlib.H>

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

    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

 void InsertSoLL(struct Node *p,int data)
   {
     struct Node *q=NULL,*t;

     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=data;
     t->next=NULL;
     
     if(p == NULL){
         first=t;
     }
     else
     {
         while(p !=NULL && p->data < data){
             q=p;
             p=p->next;
         }
         if(p == first){
             t->next=first;
             first=t;
         }
         else{
             t->next=q->next;
             q->next=t;
         }
     }
    }

 int main(){
     int A[]={3,5,7,9,13};
     Create(A,5);
     InsertSoLL(first,4);
     Display(first);

 }