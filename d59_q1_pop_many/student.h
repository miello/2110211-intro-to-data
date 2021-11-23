#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  while(!empty() && K > 0) {
    K--;
    pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<T> st;
  std::vector<T> tmp;
  while(!empty() && K > 0) {
    tmp.push_back(top());
    pop();
    K--;
  }

  for(int i = tmp.size() - 1; i >= 0; i--) {
    st.push(tmp[i]);
  }

  return st;
}

#endif
