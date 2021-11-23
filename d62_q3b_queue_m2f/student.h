#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    size_t front = mFront, back = mFront + pos;
    for(size_t i = back; i > front; i--) {
        T tmp = mData[i % mCap];
        mData[i % mCap] = mData[(i - 1) % mCap];
        mData[(i - 1) % mCap] = tmp;
    }
}

#endif
