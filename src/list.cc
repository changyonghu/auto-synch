#include <iostream>
#include "linklist.h"

using namespace std;

int main(){
    linklist a;
    a.mylist.push_back(1);
    a.mylist.push_back(2);
    a.mylist_iter = a.mylist.end();
    a.mylist_iter--;
    //a.mylist_iter++;
    cout << *(a.mylist_iter) << endl;
}
