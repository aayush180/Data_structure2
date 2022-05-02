#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("Stack Is Full\n");
    }
    else{
        t->data = x;
        t->next=top;
        top=t;
    }

}

int pop(){
    int x=-1;
    struct Node *t=top;

    if(top == NULL){
        printf("Stack is Empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int peek(int pos){
    struct Node *p=top;
    
    for(int i=0;p != NULL && i<pos-1;i++){
        p=p->next;
    }
    if(p != NULL){
        return p->data;
    }
    else{
        return -1;
    }
}

int StackTop(){
    if(top == NULL){
        return -1;
    }
    else{
        return top->data;
    }
}


void  Display(){
    struct Node *p=top;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    
    printf("peek Element is:%d\n",peek(2));
    

    Display();
}