/*************************************************************************
	> File Name: cond_mgr.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2016 04:33:36 PM CDT
 ************************************************************************/

#ifndef _COND_MGR_H
#define _COND_MGR_H

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <map>
#include <condition_variable>
#include "predicate.h"

using namespace std;


class CondMgr {

    vector<Predicate*> predicateQ_;
    mutex mutex_;
    //unique_lock<mutex> guard_;
    map<Predicate*, condition_variable*> map_;
    map<Predicate*, unique_lock<mutex>*> lock_map_;


public:

    CondMgr(void){}// { guard_ = unique_lock<mutex> (mutex_, defer_lock); 
    void waituntil(Predicate& prd, unique_lock<mutex>* guard);
    void autosignal(unique_lock<mutex>* guard);
    void AppendPredicate(Predicate* prd){
        predicateQ_.push_back(prd);
    } 

};

#endif
