class Solution {
public:
    int houserob_top_down(int i,int n,vector<int>&v,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int steal = v[i] + houserob(i+2,n,v,dp);
        int skip = houserob(i+1,n,v,dp);

        return dp[i] = max(steal,skip);
    }

    int houserob_bottom_up(int n,vector<int>&v){
           vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = v[0];
        if(n==1) return v[0];
        if(n==0) return 0;
        for(int i=2;i<=n;i++) {
            int steal = v[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(steal,skip);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = houserob_top_down(0,n,nums,dp);
        return ans;
    }
};
