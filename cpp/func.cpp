#include<iostream>
#include<vector>

using namespace std;

class A{
    public:
        int a;   
        A(){cout<<"construct A"<<endl;}
        A(const A& t){cout<<"construct from another A"<<endl;}
};

void f1(A a){
    cout<<"f1"<<endl;
}
void f2(vector<A> a){
    cout<<"f2"<<endl;
}
void f3(A a[3]){
    cout<<"f3"<<endl;
}
void f4(A a[]){
    cout<<"f4"<<endl;
}

int main(){
    A a;
    f1(a);
    cout<<"vector<A> v(3, a)"<<endl;
    vector<A> v(3);
    cout<<"begin f2"<<endl;
    f2(v);
    cout<<"end f2"<<endl;
    cout<<"A[3]"<<endl;
    A arr[3];
    cout<<"begin f3"<<endl;
    f3(arr);
    cout<<"end f3"<<endl;
    cout<<"begin f4"<<endl;
    f4(arr);
    cout<<"end f4"<<endl;
    return 0;
}
