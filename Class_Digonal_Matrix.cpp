#include<iostream>
#include<stdio.h>
using namespace std;

class Digonal{
    private:
    int *A;
    int n;

    public:

    Digonal(int n){
        this->n = n;
    }
    void set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Digonal(){
        delete [] A;
    }
};

void Digonal::set(int i,int j,int x){
    if(i== j){
       A[i-1]=x;
    }
}

int Digonal::Get(int i,int j){

    if(i == j){
        return A[i-1];
    }
    else{
        return 0;
    }
}

void Digonal::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<A[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    Digonal d(4);
    d.Get(2,2);
    
    d.set(1,1,3);
    d.set(2,2,5);
    d.set(3,3,7);
    d.set(4,4,9);

    d.Display();
}