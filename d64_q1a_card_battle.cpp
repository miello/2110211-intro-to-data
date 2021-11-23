#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<int, int> ajCard;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ajCard[x]++;
    }

    int round = 1;

    for(int i = 0; i < m; i++, round++) {
        int t, query;
        cin >> t;
        while(t--) {
            cin >> query;
            auto it = ajCard.upper_bound(query);

            if(it == ajCard.end()) {
                cout << round;
                return 0;
            }

            if(it->second >= 1) {
                it->second--;
            }

            if(it->second == 0) {
                ajCard.erase(it);
            }
        }
    }
    cout << round;
}