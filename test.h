#ifndef TEST_H
#define TEST_H

#include <chrono>
#include <mutex>
#include <condition_variable>
#include "myvector.h"

namespace cpp_primer
{
template<typename From, typename To>
class Test
{
public:
    explicit Test(){}
public:
    void test();
private:
    static uint8_t t(To*);
    static uint16_t t(...);
public:
    enum { Value  = sizeof(t((From*)nullptr)) - 1 };
};
}

#endif // TEST_H
