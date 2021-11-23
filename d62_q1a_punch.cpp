#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> finalVal;

    for(auto i = v.begin(); i < it - k; i++) {
        finalVal.push_back(*i);
    }

    for(auto i = it + k + 1; i < v.end(); i++) {
        finalVal.push_back(*i);
    }

    return finalVal;
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