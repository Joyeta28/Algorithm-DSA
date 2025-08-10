//bottom up

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));

    for (int i = 1; i <= n; i++) {              // items 1..n
        for (int cap = 0; cap <= W; cap++) {    // capacity 0..W
            ll not_take = dp[i - 1][cap];       // skip current item
            ll take = 0;
            if (w[i - 1] <= cap) {
                take = v[i - 1] + dp[i - 1][cap - w[i - 1]];
            }
            dp[i][cap] = max(take, not_take);
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
