#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, m, x;
    scanf("%d %d %d", &h, &m, &x);
    
    int newTime = (h * 60 + m + x) % 1440;
    int newM = newTime % 60;
    int newH = (newTime - newM) / 60;
    printf("%02d %02d", newH, newM);
}