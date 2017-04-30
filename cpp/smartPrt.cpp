#include<iostream>

using namespace std;

template<typename T>
class SmartPtr;

template<typename T>
class RefPtr{
    private:
        friend class SmartPtr<T>;
        int count;
        T* ptr;
        RefPtr(T* p):count(1),ptr(p){
            cout<<"new RefPtr "<<ptr<<endl;
        }
        ~RefPtr(){
            cout<<"RefPtr delete "<<ptr<<endl;
            delete ptr;
        }
};


template<typename T>
class SmartPtr{
    RefPtr<T> * rPtr;
    public:
    SmartPtr(T* ptr):rPtr(new RefPtr<T>(ptr)){
        cout<<"new SmartPtr with pointer "<<ptr<<endl;
    }
    SmartPtr(SmartPtr<T>& s):rPtr(s.rPtr){
        rPtr->count++;
        cout<<"new SmartPtr with SmartPtr "<<rPtr->ptr<<" count "<<rPtr->count<<endl;
    }
    ~SmartPtr(){
        rPtr->count--;
        cout<<"~SmartPtr for "<<rPtr->ptr<<" count "<<rPtr->count<<endl;
        if(rPtr->count==0){
            delete rPtr;
        }
    }
    SmartPtr<T>& operator=(SmartPtr<T>& s){
        rPtr->count--;
        cout<<"=SmartPtr for "<<rPtr->ptr<<" count "<<rPtr->count<<endl;
        if(rPtr->count==0){
            delete rPtr;
        }
        rPtr = s.rPtr;
        rPtr->count++;
        cout<<"=SmartPtr for "<<rPtr->ptr<<" count "<<rPtr->count<<endl;
        return *this;
    }
    T& operator*(){
        return *(rPtr->ptr);
    }
    T* operator->(){
        return rPtr->ptr;
    }
};

template<typename T>
void f1(SmartPtr<T>& s){
    cout<<"func1 &"<<endl;
}

template<typename T>
void f2(SmartPtr<T> s){
    cout<<"func2"<<endl;
}

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
