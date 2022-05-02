#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Create(int key){
    struct Node *t=root;
    struct Node *r,*p;

   if(root==NULL){
       p=(struct Node *)malloc(sizeof(struct Node));
       p->data=key;
       p->lchild=p->rchild=NULL;
       root=p;
       return;
   }
   while(t!=NULL){
       r=t;
       if(key <t->data){
           t=t->lchild;
       }
       else if(key >t->data){
           t=t->rchild;
       }
       else{
             return;
       }
   }

   p=(struct Node *)malloc(sizeof(struct Node));
   p->data=key;
   p->lchild=p->rchild=NULL;

   if(key < r->data){
       r->lchild=p;
   }
   else{
       r->rchild=p;
   }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

int Height(struct Node *p){
    int x=0,y=0;

    if(p==NULL){
        return 0;
    }
    else{
        x=Height(p->lchild);
        y=Height(p->rchild);
        return x>y?x+1:y+1;
    }
}

struct Node *Inpree(struct Node *p){

    while(p && p->rchild!=NULL){
       p=p->rchild;
    }
    return p;
}

struct Node *Insucc(struct Node *p){
    while(p && p->lchild!=NULL){
        p=p->lchild;
    }
    return p;
}

struct Node *Delete1(struct Node *p,int key){
     
     struct Node *q;

     if(p==NULL){
        return NULL;
     }
     if(p->lchild==NULL && p->rchild==NULL){
         if(p==root){
             root=NULL;
         }
         free(p);
         return NULL;
     }
     else{
     if(key < p->data){
         p->lchild=Delete1(p->lchild,key);
     }
     else if(key > p->data){
         p->rchild=Delete1(p->rchild,key);
     }
     else{
         if(Height(p->lchild)>Height(p->rchild))
         {
            q=Inpree(p->lchild);
            p->data=q->data;
            p->lchild=Delete1(p->lchild,q->data);
         }
         else{
             q=Insucc(p->rchild);
             p->data=q->data;
             p->rchild=Delete1(p->rchild,q->data);
         }
     }
     }
     return p;
}

int main(){
    Create(30);
    Create(25);
    Create(40);
    Create(15);
    Create(35);

    Delete1(root,40);
    
    Inorder(root);


}