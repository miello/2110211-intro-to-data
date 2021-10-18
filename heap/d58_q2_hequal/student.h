#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  std::vector<T> x, y;
  if(mSize != other.mSize) return false;

  for(int i = 0; i < mSize; i++) {
    x.push_back(mData[i]);
    y.push_back(other.mData[i]);
  }

  std::sort(x.begin(), x.end(), mLess);
  std::sort(y.begin(), y.end(), other.mLess);

  for(int i = 0; i < mSize; i++) {
    if(x[i] != y[i]) return false;
  }
  //write your code here
  return true; // you can change this line
}

#endif
