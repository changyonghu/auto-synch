#include "boundedbuffer.h"

BoundedBuffer::BoundedBuffer(int n) : buff(n)
{
    putPtr = takePtr = count = 0;
}


void BoundedBuffer::put ( vector<int> items )
{
    Predicate prd(count,buff.capacity()-items.size(),LTE);
    cond_mgr.waituntil(prd);
    for(int i = 0; i < items.size(); i++){
        buff[putPtr++] = items[i];
        putPtr %= buff.capacity();
    }
    count += items.size();
    //std::cout << "thread put and #items is " << count << std::endl;
    cond_mgr.autosignal();
    return;
}

vector<int> BoundedBuffer::take( int num )
{
    Predicate prd(count,num,GTE);
    cond_mgr.waituntil(prd);
    std::vector <int> ret(num);
    for( int i=0; i < num; i++ ){
        ret[i] = buff[takePtr++];
        takePtr %= buff.capacity();
    }
    count -= num;
    //std::cout << "thread take and #items is " << count << std::endl;
    cond_mgr.autosignal();
    return ret;
}

int BoundedBuffer::result(void){
    return count;
}
