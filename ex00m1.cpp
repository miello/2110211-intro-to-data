#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pq.emplace(0, t);
    }

    for(int i = 0; i < m; i++) {
        auto now = pq.top();

        cout << now.first << "\n";
        pq.pop();

        pq.emplace(now.first + now.second, now.second);
    }
}