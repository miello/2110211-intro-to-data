#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  expand(size() + 1);
  mSize++;
  int newPos = size() - pos - 1;
  for(int i = mSize - 1; i > newPos; i--) {
    mData[i] = mData[i - 1];
  }
  mData[newPos] = value;
}

#endif
