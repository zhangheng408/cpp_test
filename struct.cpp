#include<iostream>

using namespace std;

struct A{
    char a;
    int b;
    long c;
};

struct B{
    char a;
    long c;
    int b;
};

int main(){
    cout<<"sizeof(char):"<<sizeof(char)<<endl;
    cout<<"sizeof(short):"<<sizeof(short)<<endl;
    cout<<"sizeof(int):"<<sizeof(int)<<endl;
    cout<<"sizeof(long):"<<sizeof(long)<<endl;
    cout<<"sizeof(long long):"<<sizeof(long long)<<endl;
    cout<<"sizeof(double):"<<sizeof(double)<<endl;
    //struct
    cout<<"sizeof(struct {char, int, long}):"<<sizeof(A)<<endl;
    cout<<"sizeof(struct {char, long ,int}):"<<sizeof(B)<<endl;
    return 0;
}
