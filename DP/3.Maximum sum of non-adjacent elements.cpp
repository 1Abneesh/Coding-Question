#include <bits/stdc++.h>
int solve(vector<int> &nums,int indx,vector<int> &dp) {
  if (indx == 0) {
      return nums[indx];
  }
  if (indx < 0) {
      return 0;
  }
  if (dp[indx] != -1) {
      return dp[indx];
  }
  int pick = solve(nums,indx-2,dp) + nums[indx];
  int not_pick = solve(nums,indx-1,dp);
  return dp[indx] = max(pick,not_pick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size()+1,-1);
    
    return solve(nums,nums.size()-1,dp);
}