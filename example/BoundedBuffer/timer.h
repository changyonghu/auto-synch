/*************************************************************************
	> File Name: timer.h
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2016 09:05:21 PM CDT
 ************************************************************************/

#ifndef _TIMER_H
#define _TIMER_H
#include <ctime>
#include <map>
#include <string>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

class FunctionTimer{
    std::string mName;
    //struct rusage usage;
    struct timeval start, end;
    clock_t mStartTime;
    //static std::map<std::string, long int> mTicks;
    static std::map<std::string, clock_t> mFunctionTimes;
    static std::map<std::string, clock_t> mStopTimes;

public:

    FunctionTimer(char const *name) : mName(name), mStartTime(clock()){
        //getrusage(RUSAGE_THREAD, &usage);
        //start = usage.ru_utime;
    }
    ~FunctionTimer() { mFunctionTimes[mName] += clock() - mStartTime; }
    
    void stop(){ 
        clock_t tmp = clock() - mStartTime;
        //mStopTimes[mName] = clock() - mStartTime;
        mStopTimes[mName] = ((float)tmp/CLOCKS_PER_SEC)*1000000;//microseconds
        //getrusage(RUSAGE_THREAD, &usage);
        //end = usage.ru_utime;
        //std::cout << end.tv_usec << std::endl;
        //mTicks[mName] = end.tv_usec - start.tv_usec;
    }
    

    static void report(){
        /*
        for(std::map<std::string, clock_t>::iterator it = mFunctionTimes.begin(); it!=mFunctionTimes.end(); ++it){
            std::cout << "FunctionTime: " << it->first << " => " << it->second << std::endl;
        }
        */
        for(std::map<std::string, clock_t>::iterator it = mStopTimes.begin(); it!=mStopTimes.end(); ++it){
            std::cout << "StopTime: " << it->first << " => " << it->second << std::endl;
        }
        /*
        for(std::map<std::string, long int>::iterator it = mTicks.begin(); it!=mTicks.end(); ++it){
            std::cout << "StopTick: " << it->first << " => " << it->second << std::endl;
        }
        */
    }
};

//std::map<std::string, clock_t> FunctionTimer::mFunctionTimes;
//std::map<std::string, clock_t> FunctionTimer::mStopTimes;

#endif
