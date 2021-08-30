#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> mp;

    int n, m, k;
    cin >> n >> m >> k;

    while(n--) {
        int val;
        cin >> val;

        int l = max(0, val - k);
        int r = val + k + 1;
        mp[l]++;
        mp[r]--;
    }

    vector<int> query;

    while(m--) {
        int val;
        cin >> val;

        query.push_back(val);

        mp[val] += 0;
    }

    int nowVal = 0;

    for(auto &i: mp) {
        nowVal += i.second;
        i.second = nowVal;
    }

    for(int i: query) {
        cout << mp[i] << " ";
    }
}