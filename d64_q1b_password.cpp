#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> rotate(l);
    for(int i = 0; i < l; ++i) {
        cin >> rotate[i];
        rotate[i] %= 26;
    }

    set<string> dup;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dup.insert(s);
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); ++j) {
            s[j] = 'a' + (s[j] + rotate[j] - 'a') % 26;
        }
        cout << (dup.find(s) != dup.end() ? "Match" : "Unknown") << "\n";
    }
}