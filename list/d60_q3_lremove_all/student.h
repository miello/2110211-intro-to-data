#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  iterator head = begin();
  while(head != end()) {
    if(*head == value) {
      iterator del = head++;

      del.ptr->prev->next = del.ptr->next;
      del.ptr->next->prev = del.ptr->prev;

      mSize--;
      delete del.ptr;
    } else {
      head++;
    }
  }
}

#endif
