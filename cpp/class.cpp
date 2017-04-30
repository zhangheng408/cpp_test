#include<stdio.h>
#include<iostream>

using namespace std;

class A{
    public:
        int a;   
        virtual void fa(){}
        //static virtual void f(){}
};

class B:public A{
    public:
        int b;
        virtual void fb(){}
};
class C:public A{
    public:
        int c;
        virtual void fc(){}
};
class D:public B, public C{
    public:
        int d;
        virtual void fd(){}
};

int main(){
    D* d=new D();
    cout<<"A size: "<<sizeof(A)<<endl;
    cout<<"B size: "<<sizeof(B)<<endl;
    cout<<"C size: "<<sizeof(C)<<endl;
    cout<<"D size: "<<sizeof(D)<<endl;
    cout<<"d:"<<d<<endl;
    cout<<"d->B::a"<<&(d->B::a)<<endl;
    cout<<"d->B::b"<<&(d->B::b)<<endl;
    cout<<"d->C::a"<<&(d->C::a)<<endl;
    cout<<"d->C::c"<<&(d->C::c)<<endl;
    cout<<"d->d"<<&(d->d)<<endl;
    return 0;
}
