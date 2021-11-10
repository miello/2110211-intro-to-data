#include <bits/stdc++.h>

using namespace std;

void moving_median(vector<int> &data, int k) {
    set<pair<int, int>> s;

    for(int i = 0; i <= k; i++) {
        s.emplace(data[i], i);
    }

    auto x = s.begin();
    for(int i = 0; i < k / 2; i++) {
        x++;
    }

    cout << x->first << " ";

    for(int i = k + 1; i < data.size(); i++) {
        s.emplace(data[i], i);

        if(x->first == data[i - k - 1]) {
            if(x->second == i - k - 1) {
                if(x->first <= data[i]) {
                    ++x;
                } else if(x->first > data[i]) {
                    --x;
                }
            } else if(x->second != i - k - 1) {
                if(x->first <= data[i]) {
                    ++x;
                }
            }
        } else if (x->first > data[i - k - 1]) {
            if(x->first <= data[i]) ++x; 
        } else if (x->first < data[i - k - 1]) {
            if(x->first > data[i]) --x;
        }
        
        s.erase(make_pair(data[i - k - 1], i - k - 1));
        cout << x->first << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> tmp(n);

    for(int i = 0; i < n; i++) {
        cin >> tmp[i];
    }

    moving_median(tmp, k);
}