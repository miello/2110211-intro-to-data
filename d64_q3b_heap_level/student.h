#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <iostream>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  if((size_t)(1 << k) > mSize) return r;

  size_t first = (1 << k) - 1;
  size_t last = std::min(mSize - 1, (size_t)(1 << (k + 1)) - 2);

  for(;first <= last; ++first) {
    r.push_back(mData[first]);
  }

  std::sort(r.begin(), r.end(), mLess);
  std::reverse(r.begin(), r.end());

  return r;
}

#endif

