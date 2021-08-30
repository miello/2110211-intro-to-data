#include <set>
#include <iostream>

using namespace std;

int main() {
    set<int> ans, tmp;
    int n, m;
    
    cin >> n >> m;
    while(n--) {
        int val;
        cin >> val;
        tmp.insert(val);
    }

    while(m--) {
        int val;
        cin >> val;
        if(tmp.find(val) != tmp.end()) {
            ans.insert(val);
        }
    }

    for(int i: ans) {
        cout << i << " ";
    }
}