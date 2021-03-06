#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x < 1 || x > n) {
            cout << "NO";
            return 0;
        } 

        s.insert(x);
    }

    cout << ((s.size() == n) ? "YES" : "NO");
}