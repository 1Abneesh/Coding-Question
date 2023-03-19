class Solution {
public:
    int solve(vector<int>& nums,int k,vector<int> &dp){
        if(k==0){
            return nums[0];
        }
        if(k<0){
            return 0;
        }
        if(dp[k]!=-1){
            return dp[k];
        }
        int steal = solve(nums,k-1,dp);
        int not_steal = nums[k] + solve(nums,k-2,dp);
        return dp[k]=max(steal,not_steal);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,nums.size()-1,dp);
    }
};