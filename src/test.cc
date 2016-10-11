#include "boundedbuffer.h"
#include <thread>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include "timer.h"


using namespace std;

//#define NTHREAD 32

BoundedBuffer mybuff(256);

void put( void );
int sum_c = 0;
int sum_p = 0;

int main(int argc, char* argv[])
{
    //shared_ptr<BoundedBuffer> mybuff(new BoundedBuffer(30));
    //FunctionTimer ft("main");
    //BoundedBuffer mybuff(30);
    int num_thread = atoi(argv[1]);
    vector<int> rand_c(num_thread);
    srand(1);
    for(int i = 0; i < num_thread; i++){
        rand_c[i] = rand() % 128 + 1;
        //cout << rand_c[i] << " ";
        sum_c = sum_c + rand_c[i];
    }
    cout << endl;
    cout << "sum_c: " << sum_c << endl;
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
    thread t[num_thread];
    for(int i = 0; i < num_thread; i++){
        t[i] = thread (&BoundedBuffer::take, &mybuff, rand_c[i]);
    }
    //ft2.stop();
    //FunctionTimer ft3("main3");
    t1.join();
    for (int i = 0; i < num_thread; i++){
        t[i].join();
    }
    //ft3.stop();
    ft.stop();
    FunctionTimer::report();
    //sleep(30);
    cout << "sum_p: " << sum_p << endl;
    cout << "result: " << mybuff.result() << endl;
    return 0;
}

void put ( void ){
    while(sum_p < sum_c){
        vector<int> v(50, 1);
        mybuff.put(v);
        sum_p = sum_p + 50;
    }
}
