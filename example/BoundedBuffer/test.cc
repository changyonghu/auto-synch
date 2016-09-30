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

//#define NTHREAD 128

BoundedBuffer mybuff(256);

void put(void);
int sum_c = 0;
int sum_p = 0;
int main(int argc, char* argv[])
{ 
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

    FunctionTimer ft("main");
    thread t1 (put);
    thread t[num_thread];
    for(int i = 0; i < num_thread; i++){
        t[i] = thread (&BoundedBuffer::take, &mybuff, rand_c[i]);
    }
    t1.join();
    for (int i = 0; i < num_thread; i++){
        t[i].join();
    }
    ft.stop();
    FunctionTimer::report();
    return 0;
}

void put ( void ){ 
    while(sum_p < sum_c){
        vector<int> v (5, 1);
        mybuff.put(v);
        sum_p = sum_p + 5;
    }
}
