#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  return v.back();
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  int cnt_pop = depth >= size() ? size(): depth;
  v.insert(v.begin() + size() - cnt_pop, element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  for(auto i: w) {
    push(i);
  }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  while(!empty()) {
    if(top() == e) {
      break;
    }
    v.pop_back();
  }
}

#endif
