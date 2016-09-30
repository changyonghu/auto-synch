#include "boundedbuffer.h"
#include "timer.h"

BoundedBuffer::BoundedBuffer(int n) : buff(n)
{
    putPtr = takePtr = count = 0;
}


void BoundedBuffer::put ( vector<int> items )
{
    //FunctionTimer ft("put");
    unique_lock<mutex> guard(mymutex);
    
    while ( items.size() + count > buff.capacity() ){
        insufficientSpace.wait(guard);
    }
    
    for(int i = 0; i < items.size(); i++){
        buff[putPtr++] = items[i];
        putPtr %= buff.capacity();
    }
    count += items.size();
    insufficientItem.notify_all();
    //ft.stop();
}

vector<int> BoundedBuffer::take( int num )
{
    //FunctionTimer ft("take");
    unique_lock<mutex> guard(mymutex);
    while( count < num ){
        insufficientItem.wait(guard);
    }
    std::vector <int> ret(num);
    for( int i=0; i < num; i++ ){
        ret[i] = buff[takePtr++];
        takePtr %= buff.capacity();
    }
    count -= num;
    insufficientSpace.notify_all();
    //ft.stop();
    return ret;
}
