#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  for(size_t i = mFront; i < mFront + std::min((size_t)k, mSize); i++) {
    res.push_back(mData[i % mCap]);
  }
  //
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  size_t sz = to - from, j = 0;
  T* newQ = new T[sz]();
  for(auto i = from; i != to; i++) {
    newQ[j++] = *i;
  }
  mData = newQ;
  mSize = sz;
  mCap = sz;
  mFront = 0;
}

#endif
