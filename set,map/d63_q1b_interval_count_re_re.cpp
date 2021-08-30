#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MXN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x[MXN];

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;

        auto l = lower_bound(x, x + n, val - k);
        auto r = upper_bound(x, x + n, val + k) - 1;

        cout << (r - l + 1) << " ";
    }
}