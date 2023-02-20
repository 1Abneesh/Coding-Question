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


// bottom approach
int solve(vector<int> &nums) {
  vector<int> dp(nums.size(),-1);
  dp[0] = nums[0];
for(int i=1;i<nums.size();i++){
    int pick = nums[i];
    if(i>1){
    pick += dp[i-2];
    }
    int not_pick = dp[i-1];
    dp[i] = max(pick,not_pick);
}
  return dp[nums.size()-1];
}

// bottom up approach with space optimization

int solve(vector<int> &nums) {
  vector<int> dp(nums.size(),-1);
  dp[0] = nums[0];
    int prev_1 = nums[0];
    int prev_2 = 0;
for(int i=1;i<nums.size();i++){

    int pick = nums[i];
    if(i>1){
    pick += prev_2;
    }
    int not_pick = prev_1;
    int curr = max(pick,not_pick);
   prev_2 = prev_1;
    prev_1 = curr;
    
}
  return prev_1;
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size()+1,-1);
    
    return solve(nums,nums.size()-1,dp);
}