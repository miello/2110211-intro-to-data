#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  int thisSz = size();
  int otherSz = other.size();

  if(thisSz != otherSz) {
    return false;
  }

  thisSz--;
  while(thisSz >= 0) {
    if(mData[thisSz] != other[thisSz]) {
      return false;
    }
    thisSz--;
  }
  return true;
}

#endif
