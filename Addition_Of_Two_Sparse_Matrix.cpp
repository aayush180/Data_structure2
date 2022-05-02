#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    Element *ele;
};

void create(struct Sparse *s)
{
    cout<<"Enter Indices "<<endl;
    cin>>s->m>>s->n;

    cout<<"Enter Non Zero "<<endl;
    cin>>s->num;

    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));

    cout<<"Enter Non Zero Elements"<<endl;
    for(int i=0; i<s->num; i++){
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
    }
}

void Display(struct Sparse s)
{
int k=0;

for(int i=0;i<s.m;i++){
    for(int j=0;j<s.n;j++){
        if(i == s.ele[k].i && j == s.ele[k].j){
            cout<<s.ele[k++].x<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
    cout<<endl;
}
}

struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    int cal;
    int i,j,k;
    i=j=k=0;

    sum=(struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));

    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i <s2->ele[j].i){
            sum->ele[k++]=s1->ele[i++];
        }
        else if (s1->ele[i].i > s2->ele[j].i){
            sum->ele[k++]=s2->ele[j++];
        }
        else{
            if(s1->ele[i].j < s2->ele[j].j){
                sum->ele[k++]=s1->ele[i++];
            }
            else if (s1->ele[i].j > s2->ele[j].j)
            {
               sum->ele[k++]=s2->ele[j++];
            }
            else{
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;
            }
            
        } 
    }
    for(;i<s1->num;i++){
        sum->ele[k++]=s1->ele[i];
    }
    for(;j<s2->num;j++){
        sum->ele[k++]=s2->ele[j];
    }

    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k;

    return sum;
}


int main(){
    struct Sparse s1,s2,*s3;
    create(&s1);
    create(&s2);

    s3=add(&s1,&s2);

    printf("\n");
    printf("First Matrix\n");
    Display(s1);
    printf("Second Matrix\n");
    Display(s2);
    printf("Sum Matrix\n");
    Display(*s3);
}