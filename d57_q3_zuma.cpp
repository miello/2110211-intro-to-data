#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, v;
    vector<int> zuma;

    cin >> n >> k >> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        zuma.push_back(x);
    }

    zuma.insert(zuma.begin() + k, v);
    int f = k, s = k;
    int nowVal = zuma[k];
    int cnt = 1;

    int prevF = f, prevS = s;
    while(f >= 1 && zuma[f - 1] == nowVal) {
        ++cnt;
        --f;
    }

    while(s < zuma.size() - 1 && zuma[s + 1] == nowVal) {
        ++cnt;
        ++s;
    }


    if(cnt >= 3) {
        while(f >= 1 && s < zuma.size() - 1) {
            if(zuma[f - 1] != zuma[s + 1]) {
                break;
            }

            cnt = 0;
            prevF = f;
            prevS = s;

            nowVal = zuma[f - 1];
            while(s < zuma.size() - 1 && nowVal == zuma[s + 1]) {
                ++s;
                ++cnt;
            }
            while(f >= 1 && nowVal == zuma[f - 1]) {
                --f;
                ++cnt;
            }                

            if(cnt < 3) {
                f = prevF;
                s = prevS;
                break;
            }
        }
    } else {
        f = prevF;
        s = prevS;
    }

    if(f == s) {
        for(auto i: zuma) {
            std::cout << i << " ";
        }
        return 0;
    }

    for(int i = 0; i < f; i++) {
        std::cout << zuma[i] << " ";
    }

    for(int i = s + 1; i < zuma.size(); i++) {
        std::cout << zuma[i] << " ";
    }

}