// Subset Sum Equal To K
// Top-down approach


// note same question can be asked to divide the array in two parts and return wether it is possible to divide into two
// equall parts whose sum are equall . s1 + s2 = s; but s1 == s2 == k; 2k = s. therefeore we need to find the subarray whose sum is s/2;


bool solve(int n, int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(n==0){
        return (target == arr[0]);
    }
    if(dp[n][target] !=-1){
        return dp[n][target];
    }
    bool l = solve(n-1,target,arr,dp);
    bool r = false;
    if(target>=arr[n]){
        r = solve(n-1,target-arr[n],arr,dp);
    }
    return dp[n][target] = (l||r);
}
bottom up approach

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int target = k;
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for (int i = 0; i < n; i++) {
    //   if (target == arr[0]) {
        dp[i][0] = 1;
      }
      if (arr[0] <=k) {
          dp[0][arr[0]] =1;
      }
      for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
             bool l = dp[i-1][j];
             bool r = false;
             if(j>=arr[i]){
                r = dp[i-1][j-arr[i]];
    }
              dp[i][j] = (l||r);   
        }
      }
    return dp[n-1][k];
}

// space optimised
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int target = k;
    vector<int> dp(k+1,0);
    
    dp[0] = 1;
    if(arr[0]<=k)
        dp[arr[0]] = true;
      for (int i = 1; i < n; i++) {
          vector<int> curr(k+1,0);
            curr[0] =1;
        for (int j = 1; j <= k; j++) {
             bool l = dp[j];
             bool r = false;
             if(j>=arr[i]){
                r = dp[j-arr[i]];
    }
              curr[j] = (l||r);   
        }
        dp = curr;
      }
    return dp[k];
}