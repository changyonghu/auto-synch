#include "boundedbuffer.h"
#include <thread>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "timer.h"
#include <cstdlib>

std::map<std::string, clock_t> FunctionTimer::mFunctionTimes;
std::map<std::string, clock_t> FunctionTimer::mStopTimes;
//std::map<std::string, long int> FunctionTimer::mTicks;

using namespace std;

#define NTHREAD 256

vector<int> rand_p(NTHREAD);
BoundedBuffer mybuff(256);

void put(void);

int main()
{ 
    vector<int> rand_c(NTHREAD);
    int sum_p = 0;
    int sum_c = 0;
    srand(2);
    for(int i = 0; i < NTHREAD; i++){
        rand_p[i] = rand() % 128 + 1;
        cout << rand_p[i] << " ";
        sum_p = sum_p + rand_p[i];
    }
    cout << endl;
    for(int i = 0; i < NTHREAD; i++){
        rand_c[i] = rand() % 128 + 1;
        cout << rand_c[i] << " ";
        sum_c = sum_c + rand_c[i];
    }
    //check if #items of consumers is smaller than #items of producers
    if(sum_c > sum_p || sum_p > sum_c + 256){
        exit(1);
    }
    FunctionTimer ft("main");
    thread t1 (put);
    thread t[NTHREAD];
    for(int i = 0; i < NTHREAD; i++){
        t[i] = thread (&BoundedBuffer::take, &mybuff, rand_c[i]);
    }
    t1.join();
    for (int i = 0; i < NTHREAD; i++){
        t[i].join();
    }
    ft.stop();
    FunctionTimer::report();
    return 0;
}

void put ( void ){
    for(int i = 0; i < NTHREAD; i++){
        vector<int> v (rand_p[i], 1);
        mybuff.put(v);
    }
}
