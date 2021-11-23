#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  node *last = mHeader->prev;
  for(auto &i: ls) {
    i.mHeader->next->prev = last;
    last->next = i.mHeader->next;
    last = i.mHeader->prev;

    mSize += i.mSize;
    i.mHeader->next = i.mHeader;
    i.mHeader->prev = i.mHeader;
    i.mSize = 0;
  }
  mHeader->prev = last;
  last->next = mHeader;
}

#endif
