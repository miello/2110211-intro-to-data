#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  int sz = 0;
  for(auto i = first; i != last; i++) {
    sz++;
  }

  mData = new T[sz]();
  mCap = sz;
  mSize = sz;

  int idx = sz - 1;

  for(auto i = first; i != last; i++) {
    mData[idx--] = *i;
  }
}

#endif
