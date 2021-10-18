#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T now = mData[idx];
    while(idx > 0) {
        int newIdx = (idx - 1) / 4;
        if(mLess(now, mData[newIdx])) break;
        mData[idx] = mData[newIdx];
        idx = newIdx;
    }
    mData[idx] = now;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T now = mData[idx];
    size_t nowIdx;
    while((nowIdx = 4 * idx + 1) < mSize) {
        for(size_t i = nowIdx; i <= 4 * idx + 4 && i < mSize; i++) {
            if(mLess(mData[nowIdx], mData[i])) {
                nowIdx = i;
            }
        }

        if(mData[nowIdx] < now) break;

        mData[idx] = mData[nowIdx];
        idx = nowIdx;
    }
    mData[idx] = now;
}

#endif

