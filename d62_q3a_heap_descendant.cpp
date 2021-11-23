#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> ans;

    q.push(k);
    while(q.size()) {
        int now = q.front();

        q.pop();
        if(now >= n) continue;
        
        ans.push_back(now);

        q.push((now << 1) + 1);
        q.push((now << 1) + 2);
    }

    cout << ans.size() << "\n";
    for(auto i: ans) {
        cout << i << " ";
    }
}