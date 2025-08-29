class Solution {
public:
    int houserob(int n,vector<int>&v){
        int res1 = 0;
        int res2 = 0;
        if(n==1) return v[0];
        vector<int>dp(n+1,0);
        dp[0] = 0;
        for(int i=1;i<=n-1;i++){
            int steal = v[i-1] + (i -2>=0 ? dp[i-2]:0);
            int skip = dp[i-1];
            dp[i] = max(steal,skip);
        }
        res1 = dp[n-1];
        dp.clear();
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2;i<=n;i++){
            int steal = v[i-1] + (i>=2 ? dp[i-2]:0);
            int skip = dp[i-1];
            dp[i] = max(steal,skip);
        }
        res2 = dp[n];
        return max(res1,res2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = houserob(n,nums);
        return ans;
    }
};
