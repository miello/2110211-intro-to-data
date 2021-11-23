#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        
        bool correct[5] = {true, true, true, true, true};
        int answer[5] = {-1, -1, -1, -1, -1};

        // Fix mFront
        if((last - mSize + mCap) % mCap != mFront) {
            correct[1] = false;
            answer[1] = (last - mSize + mCap) % mCap;
        }


        // Fix mSize
        int sz = last - mFront;
        if(last < mFront) {
            sz = (last - mFront + mCap) % mCap;
        }

        if(sz != mSize) {
            correct[2] = false;
            answer[2] = sz;
        }

        // Fix mCap
        if(mSize > mCap) {
            correct[3] = false;
            answer[3] = mSize;
        }
        int insertIdx = mFront + mSize;
        if(insertIdx == last) {
            if(last + 1 > mCap) {
                correct[3] = false;
                answer[3] = last + 1;
            }
        } else {
            if(mCap != insertIdx - last) {
                correct[3] = false;
                answer[3] = insertIdx - last;
            }
        }
        
        // Fix last
        if((mFront + mSize) % mCap != last) {
            correct[4] = false;
            answer[4] = (mFront + mSize) % mCap;
        }

        bool generalPass = true;
        for(int i = 0; i < 5; i++) {
            if(!correct[i]) {
                generalPass = false;
                break;
            }
        }

        if(correction == 0) {
            cout << (generalPass ? "OK": "WRONG");
        } else {
            cout << (correct[correction] ? "OK": "WRONG");
            if(!correct[correction]) {
                cout << " " << answer[correction];
            }
        }
        cout << "\n";
    }
}
/*

3
0 0 1 0 0
0 2 4 2 0
1 2 4 0 2

*/
