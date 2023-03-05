                            // Best Time to Buy and Sell Stock II

class Solution {
public:
// Top down
    int solve(vector<int>& prices,int buy,int indx,vector<vector<int>> &dp){
        if(indx==prices.size()){
            return 0;
        }
        if(dp[indx][buy] !=-1){
            return dp[indx][buy];
        }
        if(buy){
            int taken = -prices[indx] + solve(prices,0,indx+1,dp);
            int notaken = solve(prices,1,indx+1,dp);
            return dp[indx][buy] = max(taken,notaken);
        }
        else{
            int sell = prices[indx] + solve(prices,1,indx+1,dp);
            int not_sell = solve(prices,0,indx+1,dp);
            return dp[indx][buy] = max(sell,not_sell);
        }
    }

// Bootom up Tabulation
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n = prices.size();
        for(int i=0;i<2;i++){
            dp[n][i] = 0;
        }
        // flag = buy = true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    int taken = -prices[i] + dp[i+1][1];
                    int notaken = dp[i+1][0];
                    dp[i][j] = max(taken,notaken);
                }
                else{
                    int sell = prices[i] + dp[i+1][0];
                    int not_sell = dp[i+1][1];
                    dp[i][j] = max(sell,not_sell);
                }
            }
        }
        return dp[0][0];
    }
};