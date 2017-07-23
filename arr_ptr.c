#include <stdio.h>
#include <stdlib.h>

void f1(int* p){}
void f2(int p[10]){}
void f3(int p[]){}
void f4(int p[10][10]){}
void f5(int p[][10]){}
void f6(int* p[]){}
void f7(int* p[10]){}
void f8(int** p){}
void f9(int(* p)[]){}
void f10(int(* p)[10]){}
//void f6(int p[10][]){}
//void f7(int p[][]){}

int main(){
    int a[10]={1, 2, 3, 4, 5, };
    int *p1 = (int*) malloc(10*sizeof(int));
    *p1=2;
    *(p1+1)=5;
    int *p2 = a;
    *p2=100;
    printf("a[0] %d\n", a[0]);
    f1(a);
    f2(a);
    f3(a);
    f1(p1);
    f2(p1);
    f3(p1);
    int b[10][10];
    int **p3=NULL;
    f4(p3);
    f5(p3);
    f6(p3);
    f7(p3);
    f8(p3);
    f9(p3);
    f10(p3);
    f5(b);
    f6(b);
    f7(b);
    f8(b);
    f9(b);
    f10(b);
    //f4(p3);
    //f5(p3);
    //b=(int[10])p1;
    //printf("b[0] %d\n", b[0]);
    return 0;
}
