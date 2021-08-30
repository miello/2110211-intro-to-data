#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> mp;
    int n, m;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        mp[val]++;
    }

    for(int i = 0; i < m; i++) {
        int val;
        bool found = true;
        cin >> val;

        for(auto p: mp) {
            if(p.first * 2 == val) {
                if(p.second >= 2) {
                    found = false;
                    cout << "YES" << "\n";
                    break;
                }
            } else if(mp.find(val - p.first) != mp.end()) {
                found = false;
                cout << "YES" << "\n";
                break;
            }
        }

        if(found) {
            cout << "NO" << "\n";
        }
    }
}
