#ifndef ORDERARRAY_H
#define ORDERARRAY_H

template <class T>
class OrderArray
{
public:
    OrderArray(int size, int growBy = 1)
        : array(nullptr), numElem(0), maxSize(0), growSize(0)
    {
        if (size) {
            maxSize = size;
            T* array = new T[maxSize];
            growSize = (growBy > 0) ? growBy : 0;
        }
    }

    ~OrderArray() {
        delete [] array;
        array = nullptr;
    }

    void push(T val) {

    }

private:
    T* array;
    int numElem;
    int maxSize;
    int growSize;
};

#endif // ORDERARRAY_H
