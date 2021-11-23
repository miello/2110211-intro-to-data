#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  const int targetSz = last - first;
  const int finalSz = size() + targetSz;
  T* finalMData = new T[finalSz]();

  int idx = 0;
  for(auto i = begin(); i != position; i++) {
    finalMData[idx++] = *i;
  }

  for(auto i = first; i < last; i++) {
    finalMData[idx++] = *i;
  }

  for(auto i = position; i != end(); i++) {
    finalMData[idx++] = *i;
  }

  delete[] mData;
  mData = finalMData;
  mSize = finalSz;
  mCap = finalSz;
}

#endif
