#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT,MappedT,HasherT,EqualT>::max_bucket_length() {
    size_t mx = 0;
    for(auto &i: mBuckets) {
        mx = mx < i.size() ? i.size() : mx;
    }

    return mx;
}

#endif
