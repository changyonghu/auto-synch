#include "stdlib.h"
#include "stdio.h"
#include "sys/time.h"
#include "sys/resource.h"

int getr_return, who = RUSAGE_SELF;
struct rusage usage;

int main()
{
    getr_return = getrusage(who, &usage);
    printf(" getr_return = %d\n", getr_return);

    printf(" time taken in seconds = %.6ld\n", usage.ru_utime.tv_sec);
    printf(" time taken in seconds = %.6ld\n", usage.ru_utime.tv_usec);

    int a = 22299020;
    int b = 203221219;
    int c = a+b;


        getr_return = getrusage(who, &usage);
        printf(" getr_return = %d\n", getr_return);

        printf(" time taken in seconds = %.6ld\n", usage.ru_utime.tv_sec);
        printf(" time taken in seconds = %.6ld\n", usage.ru_utime.tv_usec);

    exit;
 } 
