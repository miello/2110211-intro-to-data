#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> init, compress;

    int n, m, k;
    cin >> n >> m >> k;

    while(n--) {
        int val;
        cin >> val;

        int l = max(0, val - k);
        int r = val + k + 1;
        init.emplace_back(l, 1);
        init.emplace_back(r, -1);
    }
    
    sort(init.begin(), init.end());

    int nowVal = 0, prev = init[0].first;

    for(auto i: init) {
        if(prev != i.first) {
            compress.emplace_back(prev, nowVal);
            prev = i.first;
        }
        nowVal += i.second;
    }
    compress.emplace_back(prev, nowVal);
    
    while(m--) {
        int val;
        cin >> val;

        auto it = lower_bound(compress.begin(), compress.end(), make_pair(val, -1));
        if(it == compress.end()) {
            cout << "0 ";
            continue;
        }

        if(it->first > val && it == compress.begin()) {
            cout << "0 ";
            continue;
        }

        if(it->first > val && it != compress.begin()) {
            it--;
        }

        cout << it->second << " ";
    }
}