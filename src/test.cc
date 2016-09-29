#include "boundedbuffer.h"
#include <thread>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include "timer.h"

using namespace std;

using namespace std;

#define NTHREAD 32

vector<int> rand_p(NTHREAD);
BoundedBuffer mybuff(32001);

void put( void );

int main()
{
    //shared_ptr<BoundedBuffer> mybuff(new BoundedBuffer(30));
    //FunctionTimer ft("main");
    //BoundedBuffer mybuff(30);
    vector<int> rand_c(NTHREAD);
    int sum_p = 0;
    int sum_c = 0;
    srand(8);
    for(int i = 0; i < NTHREAD; i++){
        rand_p[i] = rand() % 5 + 1;
        cout << rand_p[i] << " ";
        sum_p = sum_p + rand_p[i];
    }
    cout << endl;
    for(int i = 0; i < NTHREAD; i++){
        rand_c[i] = rand() % 128 + 1;
        cout << rand_c[i] << " ";
        sum_c = sum_c + rand_c[i];
    }
    /*
    //check if #items of consumers is smaller than #items of producers
    if(sum_c > sum_p || sum_p > sum_c + 256){
        exit(1);
    }
    //check if #items of consumers is smaller than #items of producers
    if(sum_c > sum_p || sum_p > sum_c + 256){
        exit(1);
    }
    */
    FunctionTimer ft("main");
    
    thread t1 (put);
    //sleep(1);
    thread t[NTHREAD];
    for(int i = 0; i < NTHREAD; i++){
        t[i] = thread (&BoundedBuffer::take, &mybuff, rand_c[i]);
    }
    //ft2.stop();
    //FunctionTimer ft3("main3");
    t1.join();
    for (int i = 0; i < NTHREAD; i++){
        t[i].join();
    }
    //ft3.stop();
    ft.stop();
    FunctionTimer::report();
    //sleep(30);
    return 0;
}

void put ( void ){
    for(int i = 0; i < NTHREAD*50; i++){
        vector<int> v(2, 1);
        //vector<int> v (rand_p[i], 1);
        mybuff.put(v);
    }
}
