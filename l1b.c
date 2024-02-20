#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Hello World\n");
    fork();
    printf("\nI am after forking");
    printf("\nI am a process %d\n",getpid());
    return 0;
}