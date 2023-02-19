#include <bits/stdc++.h>

int solve(int n, vector<int> &heights,vector<int>& dp) {
if (n == 0) {
    return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int left = solve(n-1,heights,dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if (n > 1) {
       right = solve(n - 2, heights,dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    int answer = solve(n-1,heights,dp);
    return answer;

}


// bottom up approach
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    dp[0] = 0;
    // int answer = solve(n-1,heights,dp);
    for (int i = 1; i < n; i++) {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if (i > 1) {
         right = dp[i - 2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}