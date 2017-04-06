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

    Vector(int s, double initVal)
        :Vector(s)
    {
        initValue(initVal);
    }

    ~Vector()
    {
        sz = 0;
        delete[] elem;
    }

    Vector(const Vector& other)
    {
        sz = other.sz;
        elem = {new double[sz]};
        for(int i=0; i<sz; ++i)
        {
            elem[i] = other[i];
        }
    }

    Vector& operator=(const Vector& other)
    {
        sz = other.sz;
        double* newElem = {new double[other.size()]};
        for(int i=0; i<sz; ++i)
        {
            newElem[i] = other[i];
        }
        delete[] elem;
        elem = newElem;
        return *this;
    }

public:
    double& operator[](int i)
    {
        if(i<0 || size()<=i)
            throw out_of_range{"Vector::operator[]"};
        return elem[i];
    }

    double& operator[](int i) const
    {
        if(i<0 || size()<=i)
            throw out_of_range{"Vector::operator[]"};
        return elem[i];
    }

    int size(){return sz;}

    int size() const {return sz;}

private:
    double* elem;
    int sz;

private:
    void initValue(double initVal);
};
}


#endif // MYVECTOR_H
