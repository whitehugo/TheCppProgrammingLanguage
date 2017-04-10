#include <iostream>
#include "myvector.h"
#include "test.h"
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "vec.h"

using namespace std;
using namespace cpp_primer;
using namespace std::chrono_literals;

constexpr double square(double number)
{
    return number * number;
}

void print_square(double number)
{
    cout << "number " << number << "'s square is " << square(number) << endl;
}

template<class Type>
void print_pointer_info(Type* p)
{
    cout << "pointer type : " << typeid(Type).name() << endl;
    cout << "address of pointer is " << (void*)p << ", value is " << *p << endl;
    cout << "address of ++pointer is " << (void*)++p << ", value is " << *p << endl;
    cout << "size of *pointer is " << sizeof(*p) << endl;
}

double read_and_sum(cpp_primer::Vector& v)
{
    for(int i=0; i!=v.size(); ++i)
        cin >> v[i];

    double sum = 0;
    for(int i=0; i!=v.size(); ++i)
    {
        sum += v[i];
    }
    return sum;
}

Vector testReturnDirectly()
{
    Vector v(2, 1024);
    return v;
}

Vector& testReturnByRef()
{
    Vector v(2, 1024);
    return v;
}

Vector* testReturnByPtr()
{
    Vector v(2, 1024);
    return &v;
}

Vector* testReturnHeapAllocatedVal()
{
    Vector* v = new Vector(2, 1024);
    return v;
}

void testPointer()
{
    cout << "Hello World!" << endl;
    print_square(1.234);
    cout << "size of double is " << sizeof(double) << endl;
    int x = +5;
    cout << x << endl;
    int dummy;
    cout << &dummy << endl;
    constexpr double cval = 1.22*square(1.25);
    cout << cval << endl;
    int intArray[] = {0,1,2,3};
    char charArray[] = {'a','b','c','d'};
    int* pInt = intArray;
    print_pointer_info<int>(pInt);
    char* pChar = charArray;
    print_pointer_info<char>(pChar);

    void* pVoid = nullptr;
    cout << "void* pVoid is a nullptr: " << (!pVoid ? "TRUE":"FALSE") << endl;
}

void testVector()
{
    //cpp_primer::Vector v(6);
    //cout << "sum of v is " << read_and_sum(v) << endl;

    //cpp_primer::Test t;
   // t.test();

    //fine and efficiently used move semantics
    Vector& v1 = testReturnDirectly();
    //ref to destroyed object
    Vector& v2 = testReturnByRef();
    //point to unused memory
    Vector* v3 = testReturnByPtr();
    //right but dangerous
    Vector* v4 = testReturnHeapAllocatedVal();
    //copy initialized from a destoryed vector object
    Vector v5 = testReturnByRef();
    cout << v1.size()
            << "\n"
         << v2.size()
            << "\n"
         << v3->size()
            << "\n"
         << v4->size()
            << "\n"
         << v5.size()
         << endl;
    delete v4;//bad practice
}

void tfunc()
{
    cout << "tfunc1\n";
    cout << "tfunc2\n";
    cout << "tfunc3\n";
}

struct TFunc{
    void operator()()
    {
        cout << "thread started" << "\n";
        //std::this_thread::sleep_for(2s);
        cout << "thread finished" << "\n";
    }
};

void testPassByValue(Vector* v)
{
    //v = new Vector(2,1);
    (*v)[0] = 1;
}

void testPassByRef(Vector*& v)
{
    //v = new Vector(3, 2);
    (*v)[0] = 1;
}

void interestingPassByVal(Vector* v)
{
    //(Vector*&)v = new Vector(2,1);
    (*v)[0] = 1;
    (*v)[1] = 1;
    ++(Vector*&)v;
}

void digits()
{
    for(int i=0; i<10; ++i)
    {
        cout << '0'+i << endl;//static_cast<char>('0'+i);
    }
}

template <typename From, typename To>
struct TPointerIsConvertibleFromTo
{
private:
    static uint8_t  Test(...);
    static uint16_t Test(To*);

public:
    enum { Value  = sizeof(Test((From*)nullptr)) - 1 };
};

int main(int argc, char *argv[])
{
    //testPointer();
    //testVector();

    //auto start = std::chrono::high_resolution_clock::now();
    //std::this_thread::sleep_for(2s);
    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double,std::milli> duration = end - start;
    //cout << "elapsed " << duration.count() << "\n";
//    TFunc func;
//    thread t{func};
//    thread t2{tfunc};
//    t2.join();
//    t.join();
//    cout << "about to return" << "\n";

    //using PV = Vector*;
    //PV v1 = new Vector(2, 0), v2 = new Vector(2, 0), v3 = new Vector(2, 0);
    //testPassByValue(v1);
    //testPassByRef(v2);
    //interestingPassByVal(v3);
    //cout << '0'+0 << endl;
    //digits();
   // char c = 255;
    //int i = c;
    //cout << i << "\n";
    //bool b = Test<int,Vector>::Value;
    //string s{b};
    //cout << "value is " << (b?"true":"false") << endl;

    int8_t u1 = -128;
    uint8_t u2 = u1;
    cout << int{u1} << "\n" << int{u2} << "\n";
    //char c3 = 0;
    return 0;
}


