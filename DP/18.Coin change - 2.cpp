                                            // Coin Change

class Solution {
public:
// Top down
    int solve(int amount, vector<int>& coins,int indx,vector<vector<int>>&dp){
        if(indx==0){
            if(amount%coins[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[indx][amount] !=-1){
            return dp[indx][amount];
        }
        int nottaken = solve(amount,coins,indx-1,dp);
        int taken = 0;
        if(coins[indx]<=amount){
            taken =  solve(amount-coins[indx],coins,indx,dp);
        }
        return dp[indx][amount] = taken+nottaken;
    }


// Bottom up Tabulation
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // return solve(amount,coins,coins.size()-1,dp);
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
            dp[0][i] = 1;
            }
        else{
            dp[0][i] = 0;
        }
    }
    for(int i=1;i<coins.size();i++){
        for(int j=0;j<=amount;j++){
             int nottaken = dp[i-1][j];
        int taken = 0;
        if(coins[i]<=j){
            taken =  dp[i][j-coins[i]];
        }
        dp[i][j] = taken + nottaken;
        }
    }
    return dp[coins.size()-1][amount];
    }
};