#include "autosynch.h"

void waituntil( CondMgr* cond_mgr, int &shared_var, int private_var, Operator opt ){
    
    Predicate prd (shared_var, private_var, opt);
    if(prd.AssertPredicate()){

    }
    cond_mgr->AppendPredicate(prd);
}

void autosignal( CondMgr cond_mgr ){

}
