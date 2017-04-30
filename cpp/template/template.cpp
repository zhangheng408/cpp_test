#include<iostream>
#include"SmartPtr.h"

using namespace std;

int main(){
    SmartPtr<int> sp1(new int(2));
    cout<<"begin f1"<<endl;
    f1(sp1);
    cout<<"end f1"<<endl;
    cout<<"begin f2"<<endl;
    f2(sp1);
    cout<<"end f2"<<endl;
    {
        SmartPtr<int> sp2(sp1);
        {
            SmartPtr<int> sp3 = sp1;
            *sp1=1;
            cout<<*sp1<<endl;
            cout<<*sp2<<endl;
            cout<<*sp3<<endl;
            SmartPtr<int> sp4(new int(4));
            sp2=sp4;
        }
    }
    return 0;
}
