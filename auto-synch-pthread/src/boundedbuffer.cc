#include "boundedbuffer.h"

BoundedBuffer::BoundedBuffer(int n) : buff(n)
{
    putPtr = takePtr = count = 0;
}


void BoundedBuffer::put ( vector<int> items )
{
    Predicate prd(count,buff.capacity()-items.size(),LTE);
    unique_lock<mutex>* guard = new unique_lock<mutex>;
    cond_mgr.waituntil(prd,guard);
    for(int i = 0; i < items.size(); i++){
        buff[putPtr++] = items[i];
        putPtr %= buff.capacity();
    }
    count += items.size();
    //std::cout << "thread put and #items is " << count << std::endl;
    cond_mgr.autosignal(guard);
    return;
}

vector<int> BoundedBuffer::take( int num )
{
    Predicate prd(count,num,GTE);
    unique_lock<mutex>* guard = new unique_lock<mutex>;
    cond_mgr.waituntil(prd,guard);
    std::vector <int> ret(num);
    for( int i=0; i < num; i++ ){
        ret[i] = buff[takePtr++];
        takePtr %= buff.capacity();
    }
    count -= num;
    //std::cout << "thread take and #items is " << count << std::endl;
    cond_mgr.autosignal(guard);
    return ret;
}
