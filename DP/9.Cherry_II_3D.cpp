                                                // Cherry pickup 2

class Solution {
public:
//DP top down approach 
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>grid[0].size()-1 || j2<0 || j2>grid[0].size()-1){
            return INT_MIN;
        }
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int dir1[] = {-1,0,1};
        int dir2[] = {-1,0,1};
        int mini = INT_MIN;
        for(int p=0;p<3;p++){
            for(int j=0;j<3;j++){
                if(j1==j2){
                    int d = grid[i][j1] + solve(grid,i+1,j1+dir1[p],j2+dir2[j],dp);
                    mini = max(mini,d);
                }
                else{
                    int d = grid[i][j1] + grid[i][j2] + solve(grid,i+1,j1+dir1[p],j2+dir2[j],dp);
                    mini = max(mini,d);
                }
            }
        }
        return dp[i][j1][j2] = mini;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector < vector < vector < int >>> dp(grid.size(), vector < vector < int >> (grid[0].size(), vector < int> (grid[0].size(), -1)));
        return solve(grid,0,0,grid[0].size()-1,dp);
    }
};