#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::vector<std::pair<T, size_t>> ans;
    std::map<T, size_t> cnt;
    for(size_t j = mFront; j < mFront + mSize; j++) {
        cnt[mData[j % mCap]]++;
    }

    for(auto &i: k) {
        ans.push_back(std::make_pair(i, cnt[i]));
    }

    return ans;
}

#endif
