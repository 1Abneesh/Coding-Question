//DP top down approach

int solve(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>& dp){
        if(i==n-1){
            return matrix[n-1][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int l =INT_MAX;
        int r =INT_MAX;
        int d =INT_MAX;
        l = matrix[i][j] + solve(matrix,i+1,j,n,dp);
        if(j<n-1){
        r = matrix[i][j] + solve(matrix,i+1,j+1,n,dp);
        }
        if(j>0){
        d = matrix[i][j] + solve(matrix,i+1,j-1,n,dp);
        }
        return dp[i][j] = min(l,min(r,d));
    }



    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i=0;
        int j=0;
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            ans = min(ans,solve(matrix,i,j,n,dp));
        }
        
        return ans;
    }
};



// bottom up
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int l =INT_MAX;
                int r =INT_MAX;
                int d =INT_MAX;
                l = matrix[i][j] + dp[i+1][j];
                if(j<n-1){
                r = matrix[i][j] + dp[i+1][j+1];
                }
                if(j>0){
                d = matrix[i][j] + dp[i+1][j-1];
                }
                dp[i][j] = min(l,min(r,d));
            }
        }

// here our answer will stored in zero row and column and we have to returned min of it
        for(int i=0;i<n;i++){
                ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};


// bottom up with space optimisation
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<int> dp(n,0);
        vector<int> curr(n,0);
        for(int i=0;i<n;i++){
            dp[i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int l =INT_MAX;
                int r =INT_MAX;
                int d =INT_MAX;
                l = matrix[i][j] + dp[j];
                if(j<n-1){
                r = matrix[i][j] + dp[j+1];
                }
                if(j>0){
                d = matrix[i][j] + dp[j-1];
                }
                curr[j] = min(l,min(r,d));
            }
            dp = curr;
        }

        for(int i=0;i<n;i++){
                ans = min(ans,dp[i]);
        }
        return ans;
    }
};
