#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int bit = (int)log2(n);
    if(1 << bit == n) {
        cout << 0;
    } else {
        cout << (1 << (bit + 1)) - n;
    }

}