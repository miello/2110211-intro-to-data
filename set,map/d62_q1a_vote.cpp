#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> candidate;
vector<pair<int, string>> score;

int main() {
    int n, k;
    cin >> n >> k;

    while(n--) {
        string s;
        cin >> s;

        candidate[s]++;
    }

    for(auto i: candidate) {
        score.emplace_back(-i.second, i.first);
    }

    sort(score.begin(), score.end());

    auto x = score.begin() + min(k - 1, (int) score.size() - 1);
    cout << -x->first;
}