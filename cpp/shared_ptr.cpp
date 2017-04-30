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
        }
        ~RefPtr(){
            delete ptr;
        }
};


template<typename T>
class SmartPtr{
    RefPtr<T> * rPtr;
    public:
    SmartPtr(T* ptr):rPtr(new RefPtr<T>(ptr)){
    }
    SmartPtr(SmartPtr<T>& s):rPtr(s.rPtr){
        rPtr->count++;
    }
    ~SmartPtr(){
        rPtr->count--;
        if(rPtr->count==0){
            delete rPtr;
        }
    }
    SmartPtr<T>& operator=(SmartPtr<T>& s){
        rPtr->count--;
        if(rPtr->count==0){
            delete rPtr;
        }
        rPtr = s.rPtr;
        rPtr->count++;
        return *this;
    }
    T& operator*(){
        return *(rPtr->ptr);
    }
    T* operator->(){
        return rPtr->ptr;
    }
};

int main(){
    return 0;
}
