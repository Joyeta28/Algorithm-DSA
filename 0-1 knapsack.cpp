//bottom up

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >>  v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];

            if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i][j],v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }

    cout << dp[n][W] << "\n";
    return 0;
}


//top-down
#include <bits/stdc++.h>
using namespace std;
#define  ll long long
ll rec(ll i,ll W,ll n,vector<ll>&w,vector<ll>&v,vector<vector<ll>>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i][W] != -1){
        return dp[i][W];
    }
    ll not_take = rec(i+1,W,n,w,v,dp);
    ll take = 0;
    if(w[i]<=W){
       take = v[i]+rec(i+1,W-w[i],n,w,v,dp);
    }
    return dp[i][W] = max(take,not_take);
}

int main(){
       int n,W;
        cin>>n>>W;
        vector<ll>v(n);
        vector<ll>w(n);
;       for(int i=0;i<n;i++){
            cin>>w[i]>>v[i];
        }
        vector<vector<ll>>dp(n+1,vector<ll>(W+1,-1));
        ll ans = rec(0,W,n,w,v,dp);
        cout<<ans<<endl;
    return 0;
}
