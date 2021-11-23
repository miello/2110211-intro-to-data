#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int a, b;
        bool isSwap = false;

        cin >> a >> b;

        if(a > b) {
            swap(a, b);
            isSwap = true;
        }

        if(b == a) {
            cout << "a and b are the same node" << endl;
            continue;
        }

        while (b != a && b != 0) {
            b = (b - 1) >> 1;
        }

        if(a == b && isSwap) {
            cout << "b is an ancestor of a" << endl;
        } else if(a == b) {
            cout << "a is an ancestor of b" << endl;
        } else {
            cout << "a and b are not related" << endl;
        }
    }
}