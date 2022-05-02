#include<stdio.h>
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

// LEFT-LEFT-ROTATE
struct Node *LLrotate(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(p==root){
        root=pl;
    }

    return pl;
}

// LEFT-RIGHT-ROTATE
struct Node *LRrotate(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    if(p==root){
        root=plr;
    }

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    return plr;
}

//RIGHT-RIGHT-ROTATE
struct Node *RRrotate(struct Node *p){
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(p==root){
        root=pr;
    }

    return pr;
}

//RIGHT-LEFT-ROTATE
struct Node *RLrotate(struct Node *p){             //    10       ->p
    struct Node *pr=p->rchild;                     //       12     ->pr
    struct Node *prl=pr->lchild;                   //     11       ->prl

    pr->lchild=prl->rchild; 
    p->rchild=prl->lchild;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    prl->lchild=p;
    prl->rchild=pr;

    if(p==root){
        root=prl;
    }

    return prl;

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
    else if(Balancef(p)==2 && Balancef(p->lchild)==-1){
        return LRrotate(p);
    }
    else if(Balancef(p)==-2 && Balancef(p->rchild)==-1){
        return RRrotate(p);
    }
    if(Balancef(p)==-2 && Balancef(p->rchild)==1){
        return RLrotate(p);
    }


    return p;
}

int main(){
    root=Rinsert(root,10);
    Rinsert(root,12);
    Rinsert(root,11);

    Inorder(root);
}