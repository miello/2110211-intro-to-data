#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> data;

    while(n--) {
        int a, b;
        cin >> a >> b;

        data.emplace(a, b);
    }

    while(m--) {
        int query;
        cin >> query;

        auto pos = data.lower_bound(make_pair(query, -1));
        if(pos != data.end() && pos->first > query && pos != data.begin()) {
            pos--;
        }
        if(pos == data.end()) {
            pos--;
        }
        
        if(pos->first <= query && query <= pos->second) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
}