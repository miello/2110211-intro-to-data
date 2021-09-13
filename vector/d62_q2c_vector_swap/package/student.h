#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
  using std::swap;

  swap(this->mData, other.mData);
  swap(this->mSize, other.mSize);
  swap(this->mCap, other.mCap);
}

#endif
