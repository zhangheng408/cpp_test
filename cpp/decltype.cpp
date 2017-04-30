#include<iostream>
#include<typeinfo>
#include<cxxabi.h>

using namespace std;

#define f(a)    cout<<abi::__cxa_demangle(typeid(a).name(), NULL, NULL, NULL)<<endl;

template<typename T>
void f2(){
    cout<<abi::__cxa_demangle(typeid(T).name(), NULL, NULL, NULL)<<endl;
}

int main(){
    int i=0;
    f2<int>();
    f2<decltype(i)>();
    auto a=[](int a, char c){return a+c;};
    f2<decltype(a)>();
    //f2<decltype([](int a){return a;})>();//error: lambda-expression in unevaluated context 
    decltype(i) t1=0;
    return 0;
}
