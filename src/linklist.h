#include <iostream>
#include <list>

using namespace std;

class linklist{
public:
    list<int> mylist;
    list<int>::iterator mylist_iter;

public:
    linklist(void){
        //mylist_iter = mylist.begin();
    }

    void iter_inc(){
        mylist_iter++;
        if(mylist_iter == mylist.end()){
            mylist_iter = mylist.begin();
        }
    }

    void check(void);

};
