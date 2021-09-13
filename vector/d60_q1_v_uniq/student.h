#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
void CP::vector<T>::uniq() {
  int sz = size();
  std::map<T, bool> mp;

  int newSz = 0;

  for(int i = 0; i < sz; i++) {
    if(mp[mData[i]]) {
      continue;
    }
    newSz++;
    mp[mData[i]] = true;
  }

  T* newMData = new T[newSz]();
  for(int i = 0, j = 0; i < sz; i++) {
    if(mp[mData[i]]) {
      newMData[j++] = mData[i];
    }
    mp[mData[i]] = false;
  }

  delete[] mData;
  mData = newMData;
  mSize = newSz;
  mCap = newSz;  
}

#endif
