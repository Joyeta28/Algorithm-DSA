class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        vector<int>dp(n+1,1);
        int max_lis = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                    max_lis = max(max_lis,dp[i]);
                }
            }
        }
        return max_lis;
    }
};
