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
#include "cond_mgr.h"
#include "predicate.h"

using namespace std;

class BoundedBuffer {

    vector<int> buff;
    int putPtr, takePtr, count;
    CondMgr cond_mgr;

public:
    BoundedBuffer( int );
    void put( vector<int> );
    vector<int> take ( int );
    /*
    thread putT( vector<int> arg ){
        return thread([=] { put(arg); });
    }
    thread takeT( int arg ){
        return thread([=] { take(arg); });
    }
    */
};


#endif
