class Solution {
public:
    int solve(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>> &dp){
        if(i==dungeon.size()-1 && j == dungeon[0].size()-1){
            return (dungeon[i][j]<=0) ? 1-dungeon[i][j]:1;
        }
        int right=INT_MAX;
        int left=INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i<dungeon.size()-1){
            right=-dungeon[i][j] + solve(dungeon,i+1,j,dp);
        }
        if(j<dungeon[0].size()-1){
            left=-dungeon[i][j] + solve(dungeon,i,j+1,dp);
        }
        int cost= min(right,left);
        return dp[i][j] =(cost<=0) ? 1:cost;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(),vector<int>(dungeon[0].size(),0));
        // return solve(dungeon,0,0,dp);
        int n = dungeon.size();
        int m = dungeon[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j == m-1){
                if(dungeon[i][j]<=0){
                    dp[i][j]=1-dungeon[i][j];
        }
        else{
            dp[i][j]=1;
        }
            }
            else{
            int right=INT_MAX;
            int left=INT_MAX;
            if(i<n-1){
            right=-dungeon[i][j] + dp[i+1][j];
            }
            if(j<m-1){
            left=-dungeon[i][j] + dp[i][j+1];
            }
             int cost= min(right,left);
             if(cost<=0){
            dp[i][j] =1;
        }
        else{
            dp[i][j]=cost;
        }

        }
    }
        }
    return dp[0][0];
    }
};