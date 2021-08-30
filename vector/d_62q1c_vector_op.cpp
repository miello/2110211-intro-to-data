#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);

    int q;
    cin >> q;

    vector<int> v;

    while(q--) {
        string op;
        int val;
        cin >> op;

        if(op == "pb" || op == "d") {
            cin >> val;
        }

        if(op == "pb") {
            v.push_back(val);
        }

        if(op == "sa") {
            sort(v.begin(), v.end());
        }

        if(op == "sd") {
            sort(v.begin(), v.end(), greater<int>());
        }

        if(op == "r") {
            reverse(v.begin(), v.end());
        }

        if(op == "d") {
            v.erase(v.begin() + val);
        }
    }

    for(auto i: v) {
        cout << i << " ";
    }
}