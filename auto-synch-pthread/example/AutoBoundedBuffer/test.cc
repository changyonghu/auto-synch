#include "boundedbuffer.h"
#include <thread>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main()
{
    //shared_ptr<BoundedBuffer> mybuff(new BoundedBuffer(30));
    BoundedBuffer mybuff(30);
    vector<int> a = {1,2};
    vector<int> b = {3,4,5};
    vector<int> c = {6,7,8,9};
    //sleep(1);
    thread t1 (&BoundedBuffer::take, &mybuff, 6);
    sleep(1);
    thread t2 (&BoundedBuffer::put, &mybuff, a);
    thread t3 (&BoundedBuffer::put, &mybuff, b);
    thread t4 (&BoundedBuffer::put, &mybuff, c);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
