/*************************************************************************
	> File Name: predicate.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2016 04:33:26 PM CDT
 ************************************************************************/

#ifndef _PREDICATE_H
#define _PREDICATE_H

#include <iostream>
#include <string>

enum Operator{
    EQ = 0,
    NEQ,
    LT,
    LTE,
    GT,
    GTE
};

class Predicate{

//private:
public:
    int &shared_var_;
    int private_var_;
    Operator operator_;

public:
    Predicate(void);
    Predicate &operator=(Predicate& prd);
    Predicate(int &shared_var, int private_var, Operator opt);
    //Predicate(const Predicate &that);
    //Predicate(string predicate);
    
    bool AssertPredicate(void);
    void PrintPredicate(void){
        std::cout << shared_var_ << " " << operator_ << " " << private_var_ << std::endl;
    }
    
};

#endif
