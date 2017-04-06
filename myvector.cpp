#include "myvector.h"
#include <iostream>

void cpp_primer::Vector::initValue(double initVal)
{
    for(int i=0; i<sz; ++i)
        elem[i] = initVal;
}
