#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  int now = size();
  int pos = now - 1;
  resize(now * 2);

  while(pos >= 0) {
    mData[now] = mData[pos];
    now++;
    pos--;
  }

}

#endif
