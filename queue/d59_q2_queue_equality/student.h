#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  //write your code here
  if(size() != other.size()) {
    return false;
  }

  size_t a = mFront, b = mFront + mSize, c = other.mFront, d = other.mFront + other.mSize;
  while(a < b && c < d) {
    if(mData[a % mCap] != other.mData[c % other.mCap]) {
      return false;
    }
    a++;
    c++;
  }

  return true;
  // YOU CANNOT CALL push or pop
}

#endif
