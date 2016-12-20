#ifndef ACC_MAGNITUDE_H_INCLUDED
#define ACC_MAGNITUDE_H_INCLUDED

#include <stdint.h>

typedef struct accelData_s
{
    int32_t x;
    int32_t y;
    int32_t z;
}accelData_t;

int32_t acc_Magnitude(const accelData_t* accelData);
#endif // ACC_MAGNITUDE_H_INCLUDED
