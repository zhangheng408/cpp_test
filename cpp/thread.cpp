#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<vector>
using namespace std;

int f(int x){
    cout<<"thread "<<x<<" pid"<<getpid()<<endl;
    return 0;
}

int main(){
    return 0;
    vector<thread> vt;
    for(int i=0;i<10;++i){
        vt.push_back(thread(f, i));
    }
    for(int i=0;i<10;++i){
        vt[i].join();
    }
    return 0;
}
