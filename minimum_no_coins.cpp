#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e8;

int main() {
    int n, amnt;
    cin >> n >> amnt;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    // dp[i][j] = min coins to make sum j using first i coins
    vector<vector<int>> dp(n + 1, vector<int>(amnt + 1, INF));

    // Base case: 0 coins needed to make sum 0
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amnt; j++) {
            // skip current coin
            dp[i][j] = dp[i - 1][j];

            // take current coin (unlimited supply)
            if (j  >=  c[i - 1]  && dp[i][j - c[i - 1]] != INF) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - c[i - 1]]);
            }
        }
    }

    if (dp[n][amnt] == INF) cout << -1 << "\n";
    else cout << dp[n][amnt] << "\n";

    return 0;
}
