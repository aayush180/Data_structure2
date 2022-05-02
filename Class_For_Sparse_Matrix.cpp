#include<iostream>
using namespace std;

class Element{
    public:
    int i;
    int j;
    int x;
};

class sparse
{
    private:
    int m;
    int n;
    int num;
    Element *ele;
    
    public:
    sparse(int m,int n,int num){
        this->m = m;
        this->n = n;
        this->num = num;
        ele=new Element[this->num];
    }

    ~sparse(){
        delete[] ele;
    }

    void read(){
        cout<<"Enter Non Zero Elements \n";

        for(int i=0;i<num;i++){
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }
    }

    void Display(){
        int k=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ele[k].i==i && ele[k].j==j){
                    cout<<ele[k++].x<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
};

int main()
{
    sparse s(5,5,5);
    s.read();
    printf("\n");
    s.Display();
}