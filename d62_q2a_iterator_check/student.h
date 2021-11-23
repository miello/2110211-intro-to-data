#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  int sz = size();

  for(int i = 0; i < sz; i++) {
    if(mData + i == it) {
      return true;
    }
  }

  return false;

}

#endif
