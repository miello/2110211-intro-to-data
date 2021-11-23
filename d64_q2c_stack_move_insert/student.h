#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  int otherSz = s2.mSize;
  int sz = mSize;
  int mn = std::min(m, otherSz);
  T* tmp = new T[sz + mn]();

  int i = sz + mn - 1, j;

  for(j = 0; j < sz; ++j) tmp[j] = mData[j];
  for(j = mSize - 1; j >= sz - k; --j, --i) tmp[i] = tmp[j];
  for(j = otherSz - 1; j >= otherSz - mn; --j, --i) tmp[i] = s2.mData[j];

  mSize += mn;
  delete[] mData;
  mData = tmp;
  
  while(mn--) s2.pop();
}
#endif
