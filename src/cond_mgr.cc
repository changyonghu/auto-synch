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
    if(!pair_list_.empty()){
        if(isFirst){
            pair_list_iter_ = pair_list_.begin();
            isFirst = false;
        }
        list<prd_cond_pair>::iterator tmp_iter = pair_list_iter_;
        bool isFullCheck = false;
        while(!pair_list_iter_->prd->AssertPredicate()){
            iter_increment();
            if(pair_list_iter_ == tmp_iter){
                isFullCheck = true;
                //std::cout << "fullcheck" << std::endl;
                break;
            }
        }
        if(!isFullCheck){
            pair_list_iter_->cv->notify_one();
            list<prd_cond_pair>::iterator prev = pair_list_iter_;
            iter_increment();
            pair_list_.erase(prev);
            if(pair_list_.empty()){
                isFirst = true;
            }

        }
    }

    mutex_.unlock();
    return;

}
/*
for(int i=0; i < pair_list_.size(); i++){
        if(pair_list_[i].prd->AssertPredicate()){
            pair_list_[i].cv->notify_one();
            pair_list_.erase(pair_list_.begin()+i);
            break;
        }
    }
*/
