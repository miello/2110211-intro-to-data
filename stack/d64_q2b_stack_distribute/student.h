#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  std::vector<std::vector<T>> ans(k);

  int remain = mSize % k;
  int div = mSize / k;

  for(int i = mSize - 1, j = 0, cnt = 0; i >= 0; --i) {
    if(cnt != div) {
      ans[j].push_back(mData[i]);
      ++cnt;
    } else {
      if(remain != 0) {
        ans[j].push_back(mData[i]);
        --remain;
        ++j;
        cnt = 0;
      } else {
        ++j;
        j = j >= k ? j - k : j;
        ans[j].push_back(mData[i]);
        cnt = 1;
      }
    }
  }

  return ans;
}
#endif
