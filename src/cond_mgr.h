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
#include <list>
#include <mutex>
#include <map>
#include <condition_variable>
#include "predicate.h"

using namespace std;

struct prd_cond_pair{
    Predicate* prd;
    condition_variable_any* cv;
};

class CondMgr {

    list<prd_cond_pair> pair_list_;
    list<prd_cond_pair>::iterator pair_list_iter_;
    mutex mutex_;
    bool isFirst;


public:

    CondMgr(void){ isFirst = true; }
    void waituntil(Predicate& prd);
    void autosignal();
    
    void AppendPredicate(prd_cond_pair& pair){
        pair_list_.push_back(pair);
    } 

    void iter_increment(){
        pair_list_iter_++;
        if(pair_list_iter_ == pair_list_.end()){
            pair_list_iter_ = pair_list_.begin();
        }
    }
    

};

#endif
