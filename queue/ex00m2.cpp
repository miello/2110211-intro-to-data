#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
const int MXN = 1e6 + 1;

int product[MXN];
vector<int> v[MXN];

class AuctionOrder {
public:
    int user;
    int no;
    int bid;
    AuctionOrder(int user, int no, int bid) {
        this->user = user;
        this->no = no;
        this->bid = bid;
    }

    bool operator<(const AuctionOrder& other) const {
        if(this->bid < other.bid) {
            return true;
        } else if(this->bid > other.bid) {
            return false;
        }

        if(this->user < other.user) {
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m >> a;

    for(int i = 1; i <= n; i++) {
        cin >> product[i];
    }

    priority_queue<AuctionOrder> pq;
    map<pair<int, int>, int> mp;

    for(int i = 0; i < a; i++) {
        string action;
        cin >> action;

        if(action == "B") {
            int user, no, bid;
            cin >> user >> no >> bid;
            
            mp[make_pair(user, no)] = bid;
        } else if(action == "W") {
            int user, no;
            cin >> user >> no;
            mp[make_pair(user, no)] = -1;
        }
    }

    for(auto &i: mp) {
        if(i.second == -1) {
            continue;
        }
        pq.push(AuctionOrder(i.first.first, i.first.second, i.second));
    }

    while(!pq.empty()) {
        auto top = pq.top();
        if(product[top.no] != 0) {
            product[top.no]--;
            v[top.user].push_back(top.no);
        }
        pq.pop();
    }

    for(int i = 1; i <= m; i++) {
        sort(v[i].begin(), v[i].end());
        if(v[i].empty()) {
            cout << "NONE";
        } else {
            for(int &x: v[i]) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
}