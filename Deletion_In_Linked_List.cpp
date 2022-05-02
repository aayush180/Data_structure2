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

    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int Count(struct Node *p){
    int count=0;
    while(p != NULL){
     count++;
     p=p->next;
    }
    return count;
}

void Display(struct Node *p){
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int Delete(struct Node *p,int index){
    struct Node *q=NULL;
    int x=-1;

    if(index < 1 || index > Count(p)){
        printf("Index Is Not Valid ");
    }
    else{
        if(index == 1){
           q=first;
           x=p->data;
           first=first->next;
           free(q);
           return x;
        }
        else{
            for(int i=0;i<index && p != NULL;i++){
                q=p;
                p=->next;
            }
            q->next=p->next;
            x=p->data;
            free(p);
            return x;
        }
    }
}

int main(){
    
}

