#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    T* newMData = new T[mSize];
    if(mSize == mCap) {
        return;
    }

    for(int i = 0; i < mSize; i++) {
        newMData[i] = mData[i];
    }
    delete[] mData;

    mCap = mSize;
    mData = newMData;
}

#endif
