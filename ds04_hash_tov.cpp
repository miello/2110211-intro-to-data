#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void hash_to_vector(unordered_map<int,string> hash, vector<int> &key, vector<string> &value) {
  size_t sz = key.size();
  for(auto &i: hash) {
      key.push_back(i.first);
      value.push_back(i.second);
  }
}

int main() {
  int n;
  cin >> n;
  unordered_map<int,string> hash;
  while (n--) {
    int a;
    string st;
    cin >> a >> st;
    hash[a] = st;
  }

  vector<int> k;
  vector<string> v;
  hash_to_vector(hash,k,v);
  for (auto &x : k) cout << x << " "; cout << endl;
  for (auto &x : v) cout << x << " "; cout << endl;
}