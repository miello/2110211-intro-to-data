#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  T mx = mData[pos];
  size_t rank = 0;

  for(size_t i = 0; i < mSize; i++) {
    if(!mLess(mData[i], mx) && mData[i] != mx) {
      rank++;
    }
  }

  return rank;
}

#endif
