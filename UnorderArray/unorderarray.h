#ifndef UNORDERARRAY_H
#define UNORDERARRAY_H

#include <cassert>
#include <cstring>

template <class T>
class UnorderArray {
public:
    UnorderArray(int size, int growBy = 1)
        : array(nullptr), maxSize(0), numElem(0), growSize(0)
    {
        if(size) {
            maxSize = size;
            array = new T[maxSize];
            growSize = (growBy > 0) ? growBy : 0;
        }
    }
    ~UnorderArray() {
        delete [] array;
        array = nullptr;
    }

    void push(T val) {
        assert(array != nullptr);

        if (numElem >= maxSize) {
            expand();
        }

        array[numElem] = val;
        numElem++;
    }

    void pop() {
        if (numElem > 0)
            numElem--;
    }

    void remove(int index) {
        assert(array != nullptr);

        if (index >= maxSize)
            return;

        for (int k = index ; k < maxSize - 1; k++)
            array[k] = array[k + 1];

        maxSize--;

        if (numElem >= maxSize)
            numElem = maxSize - 1;
    }

    void clear() {
        numElem = 0;
    }

private:
    T* array;
    int maxSize;
    int numElem;
    int growSize;

    bool expand() {
        if (growSize <= 0)
            return false;

        T* temp = new T[maxSize + growSize];
        assert(temp != nullptr);

        memcpy(temp, array, sizeof(T) * maxSize);

        delete [] array;

        array = temp;

        maxSize += growSize;

        return true;
    }
};

#endif // UNORDERARRAY_H

