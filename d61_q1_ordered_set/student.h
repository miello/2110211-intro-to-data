#include <vector>
#include <map>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v = A;
    map<T, int> mp;

    for(auto &i: A) {
        mp[i]++;
    }

    for(auto &i: B) {
        if(mp.find(i) == mp.end()) {
            v.push_back(i);
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    map<T, int> mp;

    for(auto &i: B) {
        mp[i]++;
    }

    for(auto &i: A) {
        if(mp.find(i) != mp.end()) {
            v.push_back(i);
        }
    }

    return v;
}
