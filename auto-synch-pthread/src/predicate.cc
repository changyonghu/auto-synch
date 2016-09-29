#include "predicate.h"
#include "timer.h"

std::map<std::string, clock_t> FunctionTimer::mFunctionTimes;
std::map<std::string, clock_t> FunctionTimer::mStopTimes;

Predicate::Predicate(int &shared_var, int private_var, Operator opt)
    : shared_var_(shared_var), private_var_(private_var), operator_(opt){}

Predicate &Predicate::operator=(Predicate& prd){
    shared_var_ = prd.shared_var_;
    private_var_ = prd.private_var_;
    operator_ = prd.operator_;
    return *this;
}

bool Predicate::AssertPredicate(void){
    //FunctionTimer ft("predicate_profiler");
    switch (this->operator_){
        case EQ : 
            if(this->shared_var_ == this->private_var_)
                return true;
            else
                return false;
            break;
        case NEQ :
            if(this->shared_var_ != this->private_var_)
                return true;
            else
                return false;
            break;
        case LT :
            if(this->shared_var_ < this->private_var_)
                return true;
            else
                return false;
            break;
        case LTE :
            if(this->shared_var_ <= this->private_var_)
                return true;
            else
                return false;
            break;
        case GT :
            if(this->shared_var_ > this->private_var_)
                return true;
            else
                return false;
            break;
        case GTE :
            if(this->shared_var_ >= this->private_var_)
                return true;
            else
                return false;
            break;
        default :
            break;
    }
}
