#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        r1--;
        c1--;
        r2--;
        c2--;

        if (r1 > r2 || c1 > c2) {
            printf("INVALID\n");
        } else if ((r1 >= n && r2 >= n) || (c1 >= m && c2 >= m)) {
            printf("OUTSIDE\n");
        } else {
            int mx = arr[r1][c1];
            for(int j = r1; j <= min(n - 1, r2); j++) {
                for(int k = c1; k <= min(m - 1, c2); k++) {
                    mx = max(arr[j][k], mx);
                }
            }
            printf("%d\n", mx);
        }
    }
}