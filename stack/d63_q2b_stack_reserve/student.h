#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    int diff_now = mCap - mSize;
    int diff_other = other.mCap - other.mSize;

    if(diff_now == diff_other) {
        return 0;
    } else if(diff_now > diff_other) {
        return 1;
    } else {
        return -1;
    }
}

#endif
