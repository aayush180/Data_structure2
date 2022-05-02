#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
  
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
int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

// Insertion In Doubly Linked List
void Insert(struct Node *p,int index,int x){
    struct Node *t;

    if(index < 0 || index >Length(p)){
        return;
    }
    if(index == 0){
      t=(struct Node *)malloc(sizeof(struct Node));
      t->data=x;

      t->prev=NULL;
      t->next=first;
      first->prev=t;
      first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;

        t->prev=p;
        t->next=p->next;

        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}
// Deletion In Doubly Linked List
int  Delete(struct Node *p,int index){
    int x=-1;
    if(index < 1 || index > Length(p)){
        return -1;
    }
    if(index == 1){
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        x=p->data;
        free(p);
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}

void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={1,2,3,4,5};
    Create(A,5);

    Insert(first,5,10);
    Display(first);
    printf("\n");
    Delete(first,6);
    Display(first);

}
