class Solution {
public:
    int solve(vector<int> &nums,int indx,int prev,vector<vector<int>> &dp){
        if(indx==nums.size()){
            return 0;
        }
        if(dp[indx][prev+1]!=-1){
            return dp[indx][prev+1];
        }
        int notaken = solve(nums,indx+1,prev,dp);
        int taken = 0;
        if(prev==-1 || nums[indx]>nums[prev]){
            taken = 1+solve(nums,indx+1,indx,dp);
        }
        return dp[indx][prev+1] = max(taken , notaken);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        // return solve(nums,0,-1,dp);
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int notaken = dp[i+1][j+1];
                int taken = 0;
                if(j==-1 || nums[i]>nums[j]){
                    taken = 1+dp[i+1][i+1];
                        }
                        dp[i][j+1] = max(taken,notaken);
            }
        }

        return dp[0][0];
    }
};