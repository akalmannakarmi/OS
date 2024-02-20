#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    cout<<"Hello World\n";
    fork();
    cout<<"\nI am after forking";
    cout<<"\nI am a process"<<getpid()<<endl;
    return 0;
}