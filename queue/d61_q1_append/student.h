#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        size_t other_sz = s.size();
        expand(other_sz + mSize);
        
        for(size_t i = mCap - 1, j = mSize - 1; i >= other_sz; i--, j--) {
            mData[i] = mData[j];
        }

        for(size_t i = 0; i < other_sz; i++) {
            mData[i] = s.mData[i];
        }

        mSize = mCap;
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        size_t other_sz = q.size();
        expand(other_sz + mSize);
        
        for(size_t i = mCap - 1, j = mSize - 1; i >= other_sz; i--, j--) {
            mData[i] = mData[j];
        }

        for(int i = other_sz - 1, j = 0; i >= 0; i--, j++) {
            mData[i] = q.mData[j];
        }

        mSize = mCap;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        size_t other_sz = s.size();
        expand(other_sz + mSize);

        for(int i = mSize, j = other_sz - 1; j >= 0; i++, j--) {
            mData[i] = s.mData[j];
        }

        mSize = mCap;
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        size_t other_sz = q.size();
        expand(other_sz + mSize);

        for(int i = mSize, j = 0; j < other_sz; i++, j++) {
            mData[i] = q.mData[j];
        }

        mSize = mCap;
    }
}
