#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  size_t now_pos = mFront + pos + 1, back = mFront + mSize;
  for(size_t i = now_pos; i < back; i++) {
    T tmp = mData[i % mCap];
    mData[i % mCap] = mData[(i - 1) % mCap];
    mData[(i - 1) % mCap] = tmp;
  }
}

#endif
