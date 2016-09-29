#include <iostream>
#include <stdio.h>
#include <string>

#define waituntil(X,Y) \
    do { if(X) \
        printf("good %d %s\n",Y,#X);} \
    while(0)
    

int main(){
    int x = 0;
    int y = 10;
    waituntil(x==0,y);
    return 0;

}
