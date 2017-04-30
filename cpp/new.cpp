#include<new>
#include<iostream>
#include<exception>
using namespace std;
int c=0;
void newhandler(){
    cout << "The new_handler is called:" << endl;
    if(++c>=2){
        throw bad_alloc();
    }
    return;
}
int main(){
    set_new_handler (newhandler);
    try{
        if (1)
        {
            int *a = new int;
            delete a;
            cout<<a<<endl;
            cout << "Allocating 5000000 ints." << endl;
        }
    }
    catch ( exception e )
    {
        cout << e.what() << " xxx" << endl;
    }
    return 0;
}
