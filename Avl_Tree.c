#include<stdio.H>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;


int NodeHeight(struct Node *p){
    int hl,hr;

    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int Balancef(struct Node *p){
    int hl,hr;

    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;
}

struct Node *LLrotate(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    pl->rchild=p;
    p->lchild=plr;


    if(root==p){
        root=pl;
    }


    return pl;
    
}

struct Node *LRrotate(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->rchild=p;
    plr->lchild=pl;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(plr);
    plr->height=NodeHeight(plr);

    if(root==p){
        root=plr;
    }

    return plr;
}


void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node *Rinsert(struct Node *p,int key){

    struct Node *t=NULL;

    if(p==NULL){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }
     

    if(key < p->data){
        p->lchild=Rinsert(p->lchild,key);
    }
    if(key > p->data){
        p->rchild=Rinsert(p->rchild,key);
    }

    p->height=NodeHeight(p);

    if(Balancef(p)==2 && Balancef(p->lchild)==1){
        return LLrotate(p);
    }
    if(Balancef(p)==2 && Balancef(p->rchild)==-1){
        return LRrotate(p);
    }

    return p;
    
}


int main(){
  root=Rinsert(root,10);
  Rinsert(root,5);
  Rinsert(root,8);

  Inorder(root);
}