#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

template<typename T>
class SmartPtr{
    class RefPtr{
        public:
            int count;
            T* ptr;
            RefPtr(T* p);
            ~RefPtr();
    };
    RefPtr * rPtr;
    public:
    SmartPtr(T* ptr);
    SmartPtr(SmartPtr<T>& s);
    ~SmartPtr();
    SmartPtr<T>& operator=(SmartPtr<T>& s);
    T& operator*();
    T* operator->();
};

template<typename T>
void f1(SmartPtr<T>& s);

template<typename T>
void f2(SmartPtr<T> s);

#include<iostream>

using namespace std;

template<typename T>
SmartPtr<T>::RefPtr::RefPtr(T* p):count(1),ptr(p){
    cout<<"new RefPtr "<<ptr<<endl;
}
template<typename T>
SmartPtr<T>::RefPtr::~RefPtr(){
    cout<<"RefPtr delete "<<ptr<<endl;
    delete ptr;
}
template<typename T>
T* SmartPtr<T>::operator->(){
    return rPtr->ptr;
}
template<typename T>
T& SmartPtr<T>::operator*(){
    return *(rPtr->ptr);
}
template<typename T>
SmartPtr<T>::   SmartPtr(T* ptr):rPtr(new RefPtr(ptr)){
    cout<<"new SmartPtr with pointer "<<ptr<<endl;
}
template<typename T>
SmartPtr<T>::SmartPtr(SmartPtr<T>& s):rPtr(s.rPtr){
    rPtr->count++;
    cout<<"new SmartPtr with SmartPtr "<<rPtr->ptr<<" count "<<rPtr->count<<endl;
}
template<typename T>
SmartPtr<T>::~SmartPtr(){
    rPtr->count--;
    cout<<"~smartptr for "<<rPtr->ptr<<" count "<<rPtr->count<<endl;
    if(rPtr->count==0){
        delete rPtr;
    }
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr<T>& s){
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
template<typename T>
void f1(SmartPtr<T>& s){
    cout<<"func1 &"<<endl;
}

template<typename T>
void f2(SmartPtr<T> s){
    cout<<"func2"<<endl;
}

#endif
