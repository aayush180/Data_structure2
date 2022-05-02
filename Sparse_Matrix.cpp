#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
     printf("Enter The Indices \n");
     scanf("%d%d",&s->m,&s->n);

     printf("Enter The Non Zero \n");
     scanf("%d",&s->num);

     s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));

     printf("Enter The !0 Elements\n");

     for(int i=0; i<s->num; i++)
     {
          scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
     }
}

void Display(struct Sparse s)
{
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i== s.ele[k].i && j==s.ele[k].j ){
                printf("%d ",s.ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main()
{
    struct Sparse s;

    create(&s);
    printf("\n");
    Display(s);
}  