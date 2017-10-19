/*
 * ps -lT -p <pid> show thread and its' status
 * pstack <pid>
 * all thread is in S(sleep) status when deadlock
 */
#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

std::mutex m1,m2;

void f1(){
    std::cout<<"Thread "<<std::this_thread::get_id()<<" try to get m1"<<std::endl;
    m1.lock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" got m1"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Thread "<<std::this_thread::get_id()<<" try to get m2"<<std::endl;
    m2.lock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" got m2"<<std::endl;
    m1.unlock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" free m1"<<std::endl;
    m2.unlock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" free m2"<<std::endl;
}

void f2(){
    std::cout<<"Thread "<<std::this_thread::get_id()<<" try to get m2"<<std::endl;
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Thread "<<std::this_thread::get_id()<<" try to get m1"<<std::endl;
    m1.lock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" got m1"<<std::endl;
    std::cout<<"Thread "<<std::this_thread::get_id()<<" got m2"<<std::endl;
    m1.unlock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" free m1"<<std::endl;
    m2.unlock();
    std::cout<<"Thread "<<std::this_thread::get_id()<<" free m2"<<std::endl;
}

int main(){
    std::thread t1(f1);
    std::thread t2(f2);
    t1.join();
    t2.join();
    return 0;
}
