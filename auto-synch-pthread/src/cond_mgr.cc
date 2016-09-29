#include "cond_mgr.h"
#include "timer.h"

void CondMgr::waituntil( Predicate& prd, unique_lock<mutex>* guard ){
    //FunctionTimer ft("waituntil");
    //cout << "into waituntil" << endl;
    //bool mylock = guard_.try_lock();
    *guard = unique_lock<mutex>(mutex_);
    //prd.PrintPredicate();
    /*if(prd.AssertPredicate()){
        cout << "predicate is true for the first time" << endl;
        return;
    }
    */
    //else{
    while(!prd.AssertPredicate()){
        Predicate *tmp_prd = &prd;
        this->AppendPredicate(tmp_prd);
        condition_variable* cv = new condition_variable;
        map_[tmp_prd] = cv;
        //std::cout << "wait" << std::endl;
        //guard_.unlock();
        cv->wait(*guard);
    }
        //FunctionTimer ft("waituntil");
        return;
    //}
    
}


void CondMgr::autosignal(unique_lock<mutex>* guard){
    for(int i=0; i < predicateQ_.size(); i++){
        if(predicateQ_[i]->AssertPredicate()){
            //predicateQ_[i]->PrintPredicate();
            map_[predicateQ_[i]]->notify_one();
            predicateQ_.erase(predicateQ_.begin()+i);
            break;
        }
    }
    guard->unlock();
    return;
}
