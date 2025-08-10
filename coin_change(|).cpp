#include<bits/stdc++.h>
using namespace std;
#define  ll long long
const ll mod = 100000007;

int main(){
   int t;
   cin>>t;
   for(int i=1;i<=t;i++){
    ll n,amnt;
    cin>>n>>amnt;
    vector<ll>c(n),v(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
     for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(amnt+1,0));
    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=amnt;j++ ){
            dp[i][j] = dp[i-1][j];
            for(int k=1;k<=v[i-1];k++){
                if(j>=k*c[i-1]){
                    dp[i][j] = (dp[i][j] +dp[i-1][j - k*c[i-1]])%mod;
                }
                else{
                    break;
                }
            }

        }
    }
        cout<<"Case "<<i<<": "<<dp[n][amnt]<<endl;
    }

}
