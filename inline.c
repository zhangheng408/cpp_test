//__attribute__((no_instrument_function)) static inline void f(){
//Alternatively you can discover which binary optimizations are enabled by -O3 by using:
//gcc -c -Q -O3 --help=optimizers > /tmp/O3-opts
//gcc -c -Q -O2 --help=optimizers > /tmp/O2-opts
//diff /tmp/O2-opts /tmp/O3-opts | grep enabled
#include<stdio.h>
static inline void f(){
    printf("f");
    return;
}
int main(){
    f();
    return 1;
}
