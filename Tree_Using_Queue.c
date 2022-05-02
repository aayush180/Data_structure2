#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"Stack.h"

//     10
//  20    30
// 40 50 60 70

struct Node *root = NULL;

void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct queue q;
    create(&q,100);
    printf("Enter Root Data\n");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    Enqueue(&q,root);

    while(!IsEmptyqueue(&q))
    {
        p=Dequeue(&q);
        printf("Enter The Left Child Data of Node %d :",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            Enqueue(&q,t);
        }
        printf("Enter The Right Child Data of Node %d :",p->data);
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

void Preorder(struct Node *ptr){
    if(ptr){
        printf("%d ",ptr->data);
        Preorder(ptr->lchild);
        Preorder(ptr->rchild);
    }
}

void Inorder(struct Node *ptr){
    if(ptr){
        Inorder(ptr->lchild);
        printf("%d ",ptr->data);
        Inorder(ptr->rchild);
    }
}

void Postorder(struct Node *ptr){
    if(ptr){
        Postorder(ptr->lchild);
        Postorder(ptr->rchild);
        printf("%d ",ptr->data);
    }
}

void LevelOrder(struct Node *root)
{
     struct queue q;
     create(&q,100);

     printf("%d ",root->data);
     Enqueue(&q,root);

     while(!IsEmptyqueue(&q))
     {
         root=Dequeue(&q);
         if(root->lchild)
           {
             printf("%d ",root->lchild->data);
             Enqueue(&q,root->lchild);
           }
           if(root->rchild)
           {
              printf("%d ",root->rchild->data);
              Enqueue(&q,root->rchild);
           }
        }
}


void IPreorder(struct Node *p){
    struct Stack st;
    StackCreate(&st,100);


    while(p || ! isEmptyStack(st)){
       if(p){
        printf("%d ",p->data);
        Pushstack(&st,p);
        p=p->lchild;
    }
    else{
        p=Popstack(&st);
        p=p->rchild;
    }
}
}

void IInorder(struct Node *p){
    struct Stack st;
    StackCreate(&st,100);

    while(p || ! isEmptyStack(st)){
        if(p){
        Pushstack(&st,p);
        p=p->lchild;
    }
    else{
        p=Popstack(&st);
        printf("%d ",p->data);
        p=p->rchild;
    }
}
}

void IPostorder(struct Node *p)
{
    struct Stack st;
    StackCreate(&st,100);
     
    long int temp;
    while(p || !isEmptyStack(st))
    {
        if(p){
            Pushstack(&st,p);
            p=p->lchild;
        }
        else{
            temp=Popstack(&st);
            if(temp>0){
                Pushstack(&st,-temp);
                p=((struct Node *)temp)->rchild;
            }
            else{
                printf("%d ",((struct Node *)temp)->data);
                p=NULL;
            }

        }
    }
}

//For Counting The Nodes Of The Tree
int Count(struct Node *root){
    if(root){
        return Count(root->lchild)+Count(root->rchild)+1;
    }
    else{
        return 0;
    }
}

//For Counting The Height Of The Tree
int Height(struct Node *root){
    int x=0,y=0;
    if(root==NULL){
        return 0;
    }
    else{
        x=Height(root->lchild);
        y=Height(root->rchild);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
}
//For Counting Leaf Nodes Of Tree
int CountLeaf(struct Node *root){
    int x=0,y=0;
    if(root==NULL){
        return 0;
    }
    x=CountLeaf(root->lchild);
    y=CountLeaf(root->rchild);

    if(!root->lchild && !root->rchild){
        return x+y+1;
    }
    else{
        return x+y;
    }
    
}
//For Counting Nodes With Degree 20
int CountWithDeg2(struct Node *root){
    int x=0,y=0;
    if(root==NULL){
        return 0;
    }
    x=CountWithDeg2(root->lchild);
    y=CountWithDeg2(root->rchild);

    if(root->lchild && root->rchild){
        return x+y+1;
    }
    else{
        return x+y;
    }
    
}
//For Counting Nodes With Degree 1
//   10
// 20  30
//40     60  node 20,30,40 & 60 have degree 1
//70     90

int CountWithDeg1(struct Node *root){
    int x=0,y=0;
    if(root==NULL){
        return 0;
    }
    x=CountWithDeg1(root->lchild);
    y=CountWithDeg1(root->lchild);

    if(root->lchild ^ root->rchild)
    {              // This ^ will Perform xor operation(root->lchild!=NULL && root->rchild==NULL || root->lchild==NULL && root->rchild!=NULL)
        return x+y+1;
    }
    else{
        return x+y;
    }
}
int main(){
    TreeCreate();
    
    printf("%d ",CountWithDeg1(root));
}