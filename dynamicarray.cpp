#include <iostream>
#include <sstream>
#include "dynamicarray.h"

using namespace std;

const int INITIAL_CAP = 10;

DynamicArray::DynamicArray() {
    capacity = INITIAL_CAP;
    arr = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        arr[i] = 0;
    }
    len = 0;
}

DynamicArray::~DynamicArray() {
    delete arr;
}

void DynamicArray::append(int newVal) {
    int *arr2 = new int[capacity * 2];

    for (int i = 0; i < capacity; i++) {
        arr2[i] = arr[i];
    }
    if (capacity == len) {
        capacity += capacity;
    }
    int *temparr = arr;
    arr = arr2;
    arr[len] = newVal;
    len += 1;
    delete[] temparr;
}

int DynamicArray::at(int index) const {
    if ((len - 1) < index) {
        return -11111;
    }
    return arr[index];
}

int DynamicArray::sum() const {
    int temp = 0;
    for (int i = 0; i < len; ++i) {
        temp += arr[i];
    }
    return temp;
}


bool DynamicArray::remove(int valToDelete) {
    bool temp = false;
    for (int i = 0; i < len; ++i) {
        if (arr[i] == valToDelete) {

            for (int j = i; j < len; ++j) {
                arr[j] = arr[j + 1];
            }
            len = len - 1;

            if (len < (capacity / 2.0)) {
                capacity = static_cast<int>(capacity * .8);
                if (capacity < INITIAL_CAP) {
                    capacity = 10;
                }
            }
            temp = true;
            return temp;
        }
    }
    return temp;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    this->len = other.len;
    this->capacity = other.capacity;
    arr = new int[capacity];
    for (int i = 0; i < len; i++) {
        arr[i] = other.arr[i];
    }
}

bool DynamicArray::operator==(DynamicArray& other) const {
    if (this->len == other.len){
        for(int i=0; i < len; ++i){
            if (this->arr[i] != other.arr[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {

    if (arr == other.arr) {
        return *this;
    }

        int *temp = arr;
        this->len = other.len;
        this->capacity = other.capacity;
        this->arr = new int[capacity];

        for (int i = 0; i < len; ++i) {
            arr[i] = other.arr[i];
        }
        delete[] temp;

    return *this;
}

// Print all array elements
void DynamicArray::print(std::ostream &s) const {
    for (int i = 0; i < len; i++) {
        s << arr[i] << " ";
        if (i % 10 == 9) {
            s << endl; // newline every 10 elements
        }
    }




    s << endl;
}










