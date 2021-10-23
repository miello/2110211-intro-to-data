#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n, m, x;
    std::cin >> n >> m;

    std::vector<int> v1, v2;
    for(int i = 0; i < n; i++) {
        std::cin >> x;
        v1.push_back(x);
    }

    for(int i = 0; i < m; i++) {
        std::cin >> x;
        v2.push_back(x);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    size_t a = 0, b = 0;
    int prevOutput = -1;
    while(a < v1.size() && b < v2.size()) {
        if(v1[a] == v2[b]) {
            if(prevOutput != v1[a]) {
                std::cout << v1[a] << " ";
            }
            prevOutput = v1[a];
            a++;
            b++;
        } else if(v1[a] < v2[b]) {
            a++;
        } else if(v1[a] > v2[b]) {
            b++;
        }
    }
}