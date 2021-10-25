#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  node* current = output.mHeader->next;
  while(a != b) {
    if(*a == value) {
      iterator tmp = a;
      a++;

      // Erase node
      tmp.ptr->prev->next = tmp.ptr->next;
      tmp.ptr->next->prev = tmp.ptr->prev;

      // insert before current
      current->prev->next = tmp.ptr;

      tmp.ptr->next = current;
      tmp.ptr->prev = current->prev;

      current->prev = tmp.ptr;

      // Update size
      ++output.mSize;
      --mSize;
    } else {
      a++;
    }
  }
}

#endif
