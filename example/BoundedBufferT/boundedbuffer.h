/*************************************************************************
	> File Name: boundedbuffer.h
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 11:14:30 AM CDT
 ************************************************************************/

#ifndef _BOUNDEDBUFFER_H
#define _BOUNDEDBUFFER_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class BoundedBuffer {

    vector <int> buff;
    int putPtr, takePtr, count;
    mutex mymutex;
    condition_variable insufficientSpace;
    condition_variable insufficientItem;

public:
    BoundedBuffer( int );
    void put( vector<int> );
    vector<int> take ( int );

};


#endif
