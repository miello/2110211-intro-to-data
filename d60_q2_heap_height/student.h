#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  size_t x = mSize;
  int h = 0;

  while(x != 0) {
    h++;
    x >>= 1;
  }
  return h - 1;  
}

#endif

