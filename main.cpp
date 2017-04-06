#include <iostream>
#include "myvector.h"
#include "test.h"

using namespace std;
using namespace cpp_primer;

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

int main(int argc, char *argv[])
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

    //cpp_primer::Vector v(6);
    //cout << "sum of v is " << read_and_sum(v) << endl;

   // cpp_primer::Test t;
   // t.test();

    Vector& v1 = testReturnDirectly();
    Vector& v2 = testReturnByRef();
    Vector* v3 = testReturnByPtr();
    Vector* v4 = testReturnHeapAllocatedVal();
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

    //static_assert(8<=sizeof(int), "integer too small!");

    return 0;
}


