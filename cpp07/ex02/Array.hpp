#pragma once

#include <exception>

template <typename T>
class Array
{
    private:
        T *data;
        unsigned int sizearray;
    public:
        Array() : data(NULL), sizearray(0) {};
        Array(unsigned int n) : data(new T[n]()), sizearray(n) {};
        Array(const Array &other) : data(new T[other.sizearray]()), sizearray(other.sizearray)
        {
            for (unsigned int i = 0; i < sizearray; ++i)
            {
                data[i] = other.data[i];
            }
        }
        ~Array() { delete[] data; }

        Array &operator=(const Array &other) 
        {
            if (this != &other)
            {
                delete[] data;
                sizearray = other.sizearray;
                data = new T[sizearray]();
                for (unsigned int i = 0; i < sizearray; ++i)
                {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        T &operator[](unsigned int index) 
        {
            if (index >= sizearray)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        unsigned int size() const { return sizearray; }
};