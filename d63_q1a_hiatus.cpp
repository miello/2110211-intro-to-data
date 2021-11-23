#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v;

    while(n--) {
        int a, b;
        cin >> a >> b;

        v.emplace_back(a, b);
    }

    sort(v.begin(), v.end());

    while(m--) {
        int a, b;
        cin >> a >> b;

        auto pt = make_pair(a, b);

        bool found = binary_search(v.begin(), v.end(), pt);
        if(found) {
            cout << "0 0 ";
            continue;
        }

        auto it = upper_bound(v.begin(), v.end(), pt);
        if(it == v.begin()) {
            cout << "-1 -1 ";
            continue;
        }

        it--;

        cout << it->first << " " << it->second << " "; 
    }
}