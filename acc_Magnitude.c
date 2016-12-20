#include "acc_Magnitude.h"
#include <limits.h>
#include <stdlib.h>


uint32_t isqrt(uint32_t x);

/*
*   Fast 32bit unsigned integer square root function
*/
uint32_t isqrt(uint32_t x)
{
    register uint32_t op, res, one;

    op = x;
    res = 0;

    /* "one" starts at the highest power of four <= than the argument. */
    one = 1 << 30;  /* second-to-top bit set */
    while (one > op) one >>= 2;

    while (one != 0) {
        if (op >= res + one) {
            op -= res + one;
            res += one << 1;  // <-- faster than 2 * one
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

/*
*   Accelerometer magnitude computation
*   for speed reason all the computation is made on 32 bits data
*   -1 is return in case of error or overflow
*/
int32_t acc_Magnitude(accelData_t* accelData)
{
    uint32_t x,y,z,tmpSum;

    if(accelData == NULL)
        return(-1);

    // Convert to absolute value To avoid signed multiply overflow
    x = abs(accelData->x);
    y = abs(accelData->y);
    z = abs(accelData->z);

    // Check for multiply overflow
    if(x>USHRT_MAX || y>USHRT_MAX || z>USHRT_MAX)
        return(-1);

    tmpSum = x*x + y*y + z*z;

    // Check for addition overflow
    if(tmpSum<x || tmpSum<y || tmpSum<z)
         return(-1);

    return((int32_t)isqrt(tmpSum));
}



