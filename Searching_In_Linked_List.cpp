#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void Create(int A[],int n){
     struct Node*t,*last;

     first=(struct Node*)malloc(sizeof(struct Node));
     first->data=A[0];
     first->next=NULL;
     last=first;

     for(int i=1;i<n;i++){
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=A[i];
         t->next=NULL;
         last->next=t;
         last=t;
     }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

struct Node *Search(struct Node *p,int key)
{
    while(p != NULL){
        if(key ==p->data){   
            return p;
        }
        p=p->next;
    }
    return NULL;
}

// Recersive Function For Search in Linked List
struct Node *Rsearch(struct Node *p,int key){
    if(p == NULL){
        return NULL;
    }
    else if(key == p->data){
        return p;
    }
    else{
        return Rsearch(p->next,10);
    }
}

// Modified Searching In The Linked List
struct Node *Msearch(struct Node *p,int key)
{
    struct Node *q=NULL;

    while(p != NULL)
    {
        if(key == p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    
    
}
int main()
{
    int A[]={4,2,8,10,5};
    struct Node *N;

    Create(A,5);
    N=Msearch(first,10);
    N=Msearch(first,8);
    
    if(N != NULL){
        printf("The Key is Found %d\n",N->data);
    }
    else{
        printf("The Key is Not Found \n");
    }
    Display(first);
}