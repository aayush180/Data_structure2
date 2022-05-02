#include<stdio.h>
#include"Queue.h"
#include"Stack.h"

struct Node *root = NULL;

void TreeCreate(){
    struct Node *p,*t;
    int x;
    struct queue q;
    create(&q,100);
    printf("Enter The Data Of Root Node\n");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    Enqueue(&q,root);

    while(!IsEmptyqueue(&q)){
        p=Dequeue(&q);
        printf("Enter The Lchild Data Of Node %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            Enqueue(&q,t);
        }
        printf("Enter The Rchild Data Of Node %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            Enqueue(&q,t);
        }
    }
}

void Preorder(struct Node *root){
    if(root){
    printf("%d ",root->data);
    Preorder(root->lchild);
    Preorder(root->rchild);
}
}

void Inorder(struct Node *root){
    if(root){
        Inorder(root->lchild);
        printf("%d ",root->data);
        Inorder(root->rchild);
    }
}

void Ipreorder(struct Node *root){
    struct Stack st;
    StackCreate(&st,100);
    
}

int main(){
    TreeCreate();
    Preorder(root);
}