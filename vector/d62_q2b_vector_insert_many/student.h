#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  sort(data.begin(), data.end());
  int dataSz = data.size();
  int sz = size();

  T* newMData = new T[dataSz + sz]();

  size_t i = 0, j = 0, k = 0, diff = 0;
  while(i < sz && j < dataSz) {
    if(data[j].first + diff == k) {
      newMData[k] = data[j].second;
      j++;
      diff++;
    } else {
      newMData[k] = mData[i];
      i++;
    }
    k++;
  }

  while(i < sz) {
    newMData[k++] = mData[i];
    i++;
  }

  while(j < dataSz) {
    newMData[k++] = data[j].second;
    j++;
  }

  delete[] mData;
  mData = newMData;
  mSize = dataSz + sz;
  mCap = dataSz = sz;
}

#endif
