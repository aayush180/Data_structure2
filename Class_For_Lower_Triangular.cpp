#include<iostream>
#include<stdio.h>
using namespace std;

class LowerTri
{
    private:
    int *A;
    int n;

    public:
    LowerTri(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
};

void LowerTri::set(int i,int j,int x)
{
    if(i >= j){
        A[i*(i-1)/2+j-1]=x;
    }
}

int LowerTri::get(int i,int j)
{
  if(i>=j){
      return A[i*(i-1)/2+j-1];
  }
  else{
      return 0;
  }
}

void LowerTri::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(i>=j){
               printf("%d ",A[i*(i-1)/2+j-1]);
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
    printf("Enter The Dimension :");
    int n,x;
    scanf("%d",&n);

    LowerTri lm(n);

    printf("Enter The Values\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            lm.set(i,j,x);
        }
    }
    printf("\n");
    lm.Display();

}