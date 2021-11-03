#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  if(first == last) return;
  
  vector<T> tmp(last - first);
  int j = 0;
  for(auto i = first; i != last; ++i) {
    tmp[j++] = *i;
  }

  k = k % tmp.size();
  size_t now = k;

  for(auto i = first; i != last - k; ++i) {
    *i = tmp[now++];
  }

  now = 0;
  for(auto i = last - k; i != last; ++i) {
    *i = tmp[now++];
  }

}

#endif
