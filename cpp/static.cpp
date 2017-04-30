#include<new>
#include<iostream>
#include<exception>
using namespace std;

class A{
    static int a;
    const static int b;
    const static int c=1;
    public:
    static int d;
};

int A::a=1;
const int A::b=2;
int A::d=1;


int main(){
A::d=2;
    return 0;
}
