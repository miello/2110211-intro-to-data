#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::shift_left() {
  if(mSize <= 1) return;
  node* startNode = mHeader;
  node* nextNode = mHeader->next;
  node* prevNode = mHeader->prev;

  startNode->prev = nextNode;
  startNode->next = nextNode->next;

  nextNode->next->prev = startNode;

  nextNode->prev = prevNode;
  nextNode->next = startNode;

  prevNode->next = nextNode;
}

#endif
