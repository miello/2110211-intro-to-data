#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  iterator first = a;
  iterator last = b;
  if(mSize == 0 || a == b) return a;
  --last;
  while(true) {
    if(first == last) {
      break;
    }

    T tmpData = *first;
    *first = *last;
    *last = tmpData;

    first++;
    if(first == last) break;
    last--; 
  }

  return a;
}

#endif
