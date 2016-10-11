#include "cond_mgr.h"
#include "timer.h"

void CondMgr::waituntil( Predicate& prd ){

    mutex_.lock();
    while(!prd.AssertPredicate()){
        condition_variable_any cv;
        prd_cond_pair my_pair = {&prd, &cv};
        this->AppendPredicate(my_pair);
        cv.wait(mutex_);
    }
        return;
    
}


void CondMgr::autosignal(){

    for(int i=0; i < pair_list_.size(); i++){
        if(pair_list_[i].prd->AssertPredicate()){
            pair_list_[i].cv->notify_one();
            pair_list_.erase(pair_list_.begin()+i);
            break;
        }
    }
    mutex_.unlock();
    return;

}
