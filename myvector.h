#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>
using namespace std;

namespace cpp_primer
{
class Vector
{
public:
    Vector(int s)
    {
        if(s < 0)
            throw length_error{"length error"};
        elem = {new double[s]};
        sz = {s};
    }
    ~Vector()
    {
        sz = 0;
        delete[] elem;
    }
    Vector(Vector& other)
    {
        sz = other.sz;
        elem = other.elem;
    }
    Vector& operator=(Vector& other)
    {
        Vector v(other.size());
        v.elem = other.elem;
        return v;
    }

public:
    double& operator[](int i)
    {
        if(i<0 || size()<=i)
            throw out_of_range{"Vector::operator[]"};
        return elem[i];
    }
    int size(){return sz;}

private:
    double* elem;
    int sz;
};
}


#endif // MYVECTOR_H
