#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head;

void Create(int A[],int n)
{
    struct Node *t,*last;
  
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    
    for(int i=1;i<=n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
int length(struct Node *p){
    int len=0;
   do{
       len++;
       p=p->next;
   }while(p!=head);
   return len;
    
}

int Delete(struct Node *p,int index)
{
    struct Node *q;
    int x;

    if(index < 0 || index >length(p)){
        return -1;
    }

    if(index==1){
        while(p->next != head){
            p=p->next;
        }
        x=head->data;
        if(head == p){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        p=head;
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
void Display(struct Node *p){
    while(p->next != head){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={1,2,3,4,5,6};
    Create(A,6);
    
    Delete(head,3);
    Display(head);


}