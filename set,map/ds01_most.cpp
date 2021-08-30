#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, mn = -1;
    cin >> n;

    string ans;

    map<string, int> mp;
    while(n--) {
        string s;
        cin >> s;

        int newVal = mp[s] + 1;
        mp[s]++;

        if(newVal > mn) {
            ans = s;
            mn = mp[s];
        } else if(newVal == mn && s > ans) {
            ans = s;
        }
    }
    
    cout << ans << " " << mp[ans];
}