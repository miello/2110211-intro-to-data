#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  const size_t sz = size(), posSz = pos.size();
  
  for(size_t i = 0, j = 0, k = 0; i < sz; i++) {
    if(k != posSz && pos[k] == i) {
      k++;
    } else {
      mData[j] = mData[i];
      j++;
    }
  }
  mSize = j;
}

#endif
