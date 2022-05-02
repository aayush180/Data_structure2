#include<iostream>
#include<stdio.h>
using namespace std;

struct term{
    int coef;
    int expo;
};

struct poly{
    int n;
    struct term *t;
};

void create(struct poly *p)
{
    printf("Enter The No Of Terms :");
    scanf("%d", &p->n);

    p->t=(struct term *)malloc(p->n*sizeof(struct term));

    cout<<"Enter The Terms"<<endl;
    for(int i=0; i<p->n; i++){
        scanf("%d%d",&p->t[i].coef,&p->t[i].expo);
    }

}

void Display(struct poly p){
    for(int i=0; i<p.n; i++){
        printf("%dx%d+",p.t[i].coef,p.t[i].expo);
    }
    printf("\n");
}
// Addition Of Two Polynomial
struct poly *add(struct poly *p1,struct poly *p2)
{
    int i,j,k;
    i=j=k=0;
    struct poly *sum;
    sum=(struct poly *)malloc(sizeof(struct poly));
    sum->t=(struct term *)malloc((p1->n+p2->n)*sizeof(struct term));

    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].expo > p2->t[i].expo){
            sum->t[k++]=p1->t[i++];
        }
        else if(p1->t[i].expo < p2->t[i].expo){
            sum->t[k++]=p2->t[j++];
        }
        else{
            sum->t[k].expo=p1->t[i].expo;
            sum->t[k++].coef=p1->t[i++].coef+p2->t[j++].coef;
        }
    }
    for(;i<p1->n;i++){
        sum->t[k++]=p1->t[i];
    }
    for(;j<p2->n;j++){
        sum->t[k++]=p2->t[j];
    }

    sum->n=k;
    return sum;
}

int main(){
    struct poly p1,p2,*p3;
    
    create(&p1);
    create(&p2);

    p3=add(&p1,&p2);

    printf("First poly\n");
    Display(p1);
    printf("Second poly\n");
    Display(p2);
    printf("Final poly\n");
    Display(*p3);
}