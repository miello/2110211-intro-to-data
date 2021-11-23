#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  if(mSize == mCap) {
    mFront = (mCap + mFront + mSize - 1) % mCap;
  } else {
    mData[(mCap + mFront - 1) % mCap] = mData[(mCap + mFront + mSize - 1) % mCap];
    mFront = (mCap + mFront - 1) % mCap;
  }
}

#endif
