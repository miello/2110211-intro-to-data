#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  int f = (mFront + a) % mCap;
  int s = (mFront + b) % mCap;

  while(f != s) {
    std::swap(mData[f], mData[s]);
    ++f;
    
    f = f % mCap;
    if(f == s) break;

    --s;
    s = (s + mCap) % mCap;
  }
}

#endif
