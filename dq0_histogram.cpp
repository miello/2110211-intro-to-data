#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> mp;

    while(n--) {
        string s;
        cin >> s;

        mp[s]++;
    }

    for(auto &i: mp) {
        if(i.second > 1) {
            cout << i.first << " " << i.second << "\n";
        }
    }
}