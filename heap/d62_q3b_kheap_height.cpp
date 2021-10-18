#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    if(k == 1 || n == 1) {
        cout << n - 1 << endl;
        return 0;
    }

    long long s = (n) * (k - 1) + 1;
    long long ans = ceil(log(s) / log(k));

    cout << ans - 1 << endl;
}