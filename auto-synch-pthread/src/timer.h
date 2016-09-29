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

class FunctionTimer{
    std::string mName;
    clock_t mStartTime;
    static std::map<std::string, clock_t> mFunctionTimes;
    static std::map<std::string, clock_t> mStopTimes;

public:

    FunctionTimer(char const *name) : mName(name), mStartTime(clock()){}
    ~FunctionTimer() { mFunctionTimes[mName] += clock() - mStartTime; }
    void stop(){ mStopTimes[mName] += clock() - mStartTime; }

    static void report(){
        for(std::map<std::string, clock_t>::iterator it = mFunctionTimes.begin(); it!=mFunctionTimes.end(); ++it){
            std::cout << "FunctionTime: " << it->first << " => " << it->second << std::endl;
        }
        for(std::map<std::string, clock_t>::iterator it = mStopTimes.begin(); it!=mStopTimes.end(); ++it){
            std::cout << "StopTime: " << it->first << " => " << it->second << std::endl;
        }
    }
};

//std::map<std::string, clock_t> FunctionTimer::mFunctionTimes;
//std::map<std::string, clock_t> FunctionTimer::mStopTimes;

#endif
