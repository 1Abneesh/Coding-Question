// dp top - down
    int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp){
        if(m==0 && n==0){
            return grid[0][0];
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up=INT_MAX;
        int down = INT_MAX;
        if(m>0){
            up = grid[m][n]+solve(grid,m-1,n,dp);
        }
        if(n>0){
           down= grid[m][n]+solve(grid,m,n-1,dp);
        }
        return dp[m][n] =  min(up,down);
    }
    
// dp boottom-up with space optimisation
    int minPathSum(vector<vector<int>>& grid) {
        // int ans = grid[grid.size()-1][grid[0].size()-1];
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(grid,grid.size()-1,grid[0].size()-1,dp);
        vector<int> previous(n,INT_MAX);
        for(int i=0;i<m;i++){
            vector<int> current(n,INT_MAX);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    current[j] = grid[i][j];
                    continue;
                }
        int up=INT_MAX;
        int down = INT_MAX;
        if(i>0){
            up = grid[i][j]+previous[j];
        }
        if(j>0){
           down= grid[i][j]+current[j-1];
        }
        current[j] = min(up,down);
    }
    previous = current;
}
    return previous[n-1];
}
};