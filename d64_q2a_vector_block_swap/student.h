#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>
template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(m<=0)return false;
  if(a<b&&a+m-1>=b)return false;
  if(b<a&&b+m-1>=a)return false;
  if(a<begin()||a+m-1>=end())return false;
  if(b+m-1>=end()||b<begin())return false;
  T temp;
  size_t va=a-begin();
  size_t vb=b-begin();
  for(size_t i=0;i<m;++i){
    temp=mData[va+i];
    mData[va+i]=mData[vb+i];
    mData[vb+i]=temp;
  }
  return true;
}

#endif