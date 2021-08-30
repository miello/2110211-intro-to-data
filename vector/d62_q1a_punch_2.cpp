#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    int diff = 0;
    auto start = it - k;
    auto end = it + k;
    if(start < v.begin()) {
        start = v.begin();
    }

    if(end >= v.end()) {
        end = v.end() - 1;
    }

    v.erase(start, end + 1);
    return v;
}
int main()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}