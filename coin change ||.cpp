#include<bits/stdc++.h>
using namespace std;
#define  ll long long
const ll mod = 100000007;

int main(){
   int t;
   cin>>t;
   for(int i=1;i<=t;i++){
    int n,amnt;
    cin>>n>>amnt;
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(amnt+1,0));
    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=amnt;j++ ){
            dp[i][j] = dp[i-1][j];
            if(j>=c[i-1]){
               dp[i][j] = (dp[i][j]+dp[i][j-c[i-1]])%mod;
            }

        }
    }
        cout<<"Case "<<i<<": "<<dp[n][amnt]<<endl;
    }

}
