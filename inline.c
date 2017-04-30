//__attribute__((no_instrument_function)) static inline void f(){
#include<stdio.h>
static inline void f(){
    printf("f");
    return;
}
int main(){
    f();
    return 1;
}
