#include<new>
#include<iostream>
#include<exception>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void pv(vector<int>& v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

struct N{
    int v;
    char c;
    N(int a, char c):v(a),c(c){}
};

void pv(vector<N>& v){
    for(int i=0;i<v.size();++i){
        cout<<v[i].v<<" "<<v[i].c<<endl;
    }
    cout<<endl;
}

int main(){
    cout<<"sort int" <<endl;
    vector<int> v1;
    for(int i=0;i<10;++i){
        v1.push_back(i);
    }
    random_shuffle(v1.begin(), v1.end());
    pv(v1);
    sort(v1.begin(), v1.end());
    pv(v1);
    sort(v1.begin(), v1.end(), [](int a, int b){return a>b;});
    pv(v1);
    
    auto func = [](const N& a, const N& b)->bool{return a.v<b.v;};
    cout<<"sort struct" <<endl;
    vector<N> v2;
    for(int i=0;i<10;++i){
        v2.push_back(N(i, i+'a'));
    }
    random_shuffle(v2.begin(), v2.end());
    pv(v2);
    sort(v2.begin(), v2.end(), func);
    pv(v2);
    //pri
    cout<<"priority_queue"<<endl<<endl;
    priority_queue<N, vector<N>, decltype(func)> q(func);
    random_shuffle(v2.begin(), v2.end());
    for(int i=0;i<v2.size();++i){
        q.push(v2[i]);
    }
    while(!q.empty()){
        cout<<q.top().v<<" "<<q.top().c<<endl;
        q.pop();
    }
    //pri cap
    cout<<"index priority_queue"<<endl<<endl;
    random_shuffle(v2.begin(), v2.end());
    auto f2 = [&v2](const int& a, const int& b){return v2[a].v<v2[b].v;};
    priority_queue<int, vector<int>, decltype(f2)> q2(f2);
    for(int i=0;i<v2.size();++i){
        q2.push(i);
        cout<<i<<" "<<v2[i].v<<endl;
    }
    cout<<endl;
    while(!q2.empty()){
        cout<<q2.top()<<" "<<v2[q2.top()].v<<endl;
        q2.pop();
    }
    return 0;
}
