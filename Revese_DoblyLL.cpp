#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n){
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=last->next;
    t->prev=last;
    last->next=t;
    last=t;
    }
}

void Reverse(struct Node *p){
  struct Node *temp;
    while(p){
     temp=p->next;
     p->next=p->prev;
     p->prev=temp;
     p=p->prev;
     if(p != NULL && p->next == NULL){
         first=p;
     }
    }
}

void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={1,3,5,7,9};
    Create(A,5);
    Display(first);

    printf("\nAfter Reversing \n");
    Reverse(first);
    Display(first);
    
}
