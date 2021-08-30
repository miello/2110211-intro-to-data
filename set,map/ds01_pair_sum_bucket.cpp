#include <iostream>
#include <vector>
using namespace std;

const int MXN = 1e6;
int bucket[MXN];

vector<int> l;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if(bucket[val] == 0) {
            l.push_back(val);
        }

        bucket[val]++;
    }

    for(int i = 0; i < m; i++) {
        int val;
        bool found = false;

        cin >> val;

        for(auto i: l) {
            if(val - i > MXN || val - i < 0) continue;

            if(i * 2 == val) {
                if(bucket[i] >= 2) {
                    found = true;
                    cout << "YES" << "\n";
                    break;
                }
            } else if(bucket[val - i]) {
                found = true;
                cout << "YES" << "\n";
                break;
            }
        }

        if(!found) {
            cout << "NO" << '\n';
        }
    }
}