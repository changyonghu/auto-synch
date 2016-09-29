/*************************************************************************
	> File Name: autosynch.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2016 04:33:49 PM CDT
 ************************************************************************/

#ifndef _AUTOSYNCH_H
#define _AUTOSYNCH_H

#include "cond_mgr.h"

void waituntil( CondMgr cond_mgr, int &shared_var, int private_var, Operator opt );
void autosignal( CondMgr cond_mgr );

#endif
