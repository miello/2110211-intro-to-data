#include <iostream>
#include <map>

#define ll long long

using namespace std;

map<ll, ll> parent;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    while(n--) {
        ll a, b;
        cin >> a >> b;

        parent[b] = a;
    }

    while(m--) {
        ll f, s;
        cin >> f >> s;

        if(f == s) {
            cout << "NO" << "\n";
            continue;
        }

        for(int i = 0; i < 2; i++) {
            f = parent[f];
            s = parent[s];
        }

        cout << ((f == s && f != 0 && s != 0) ? "YES" : "NO") << "\n";
    }
}