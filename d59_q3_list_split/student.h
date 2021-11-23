#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if(it == end()) {
    return result;
  }
  iterator prev = it;
  --prev;

  // Update result list
  result.mHeader->next = it.ptr;
  result.mHeader->prev = mHeader->prev;

  mHeader->prev->next = result.mHeader;
  it.ptr->prev = result.mHeader;
  result.mSize = mSize - pos;

  // Update current list
  mHeader->prev = prev.ptr;
  prev.ptr->next = mHeader;  

  mSize = pos;

  return result;
}

#endif
