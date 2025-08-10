#include<bits/stdc++.h>
using namespace std;
#define  ll long long
const ll mod = 100000007;

ll rec(string s1,string s2,vector<vector<int>>&dp){
    ll n = s1.size();
    ll m = s2.size();
    for(int i=0;i<=n;i++) {
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+ min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}
int main(){
   int t=1;
   //cin>>t;
   for(int i=1;i<=t;i++){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    ll ans = rec(s1,s2,dp);
    cout<<ans<<endl;
   }
}
