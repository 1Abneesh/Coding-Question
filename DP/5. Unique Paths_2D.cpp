// dp top down approach

int solve(int m,int n,vector<vector<int>> &dp){
        if((m==0) && (n==0)){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int l = 0;
        int r = 0;
        if(m>0){
         l = solve(m-1,n,dp);
        }
        if(n>0){
            r = solve(m,n-1,dp);
        }
        return dp[m][n] =l+r;
    }
    
// dp bottom - up approach
 int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
  for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          int up=0;
          int left = 0;
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];  
          dp[i][j] = up+left;
      }
  }
  return dp[m-1][n-1]; 
}


// dp bottom - up approach with space optimisation
 int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
              vector<int> prev(n,0);
                for(int i=0; i<m ;i++){
                    vector<int> curr(n,0);
                    for(int j=0; j<n; j++){
                        //base condition
                        if(i==0 && j==0){
                            curr[j]=1;
                            continue;
                        }
                        int up=0;
                        int left = 0;
                        if(i>0) 
                            up = prev[j];
                        if(j>0)
                            left = curr[j-1];  
                        curr[j] = up+left;
                    }
                    prev = curr;
  }
  return prev[n-1]; 
}
    
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1,n-1,dp);
    }
};