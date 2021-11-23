#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  T mx = mData[0];
  size_t sz = 0;
  if(mSize >= 32) {
    sz = 32;
  } else {
    sz = mSize;
  }
  for(size_t i = 0; i < k - 1; i++) {
    T tmp;
    bool first = true;
    for(size_t j = 0; j < sz; j++) {
      if(mLess(mData[j], mx) && first) {
        tmp = mData[j];
        first = false;
      } else if(first) {
        continue;
      }
      
      if(mLess(mData[j], mx) && mLess(tmp, mData[j])) {
        tmp = mData[j];
      }
    }
    mx = tmp;
  }


  return mx;
}

#endif
