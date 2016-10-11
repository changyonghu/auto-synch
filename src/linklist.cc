

#include "linklist.h"

void linklist::check(void){
    list<int>::iterator tmp = mylist_iter;
    bool isFullCheck = false;
    while(1){
        iter_inc();
        if(mylist_iter == tmp){
            isFullCheck = true; 
            break;
        }
    }
    if(!isFullCheck){
        mylist_.erase(mylist_iter_++);
    }
}
