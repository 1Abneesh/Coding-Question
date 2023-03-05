class Solution {
public:
                                    // Top down
    int solve(vector<int>& prices,int buy,int indx,int count,vector<vector<vector<int>>> &dp){
        if(indx==prices.size()){
            return 0;
        }
        if(count==0){
            return 0;
        }
        if(dp[indx][buy][count] !=-1){
            return dp[indx][buy][count];
        }
        if(buy){
            int taken = -prices[indx] + solve(prices,0,indx+1,count,dp);
            int notaken = solve(prices,1,indx+1,count,dp);
            return dp[indx][buy][count] =  max(taken,notaken);
        }
        else{
            int sell = prices[indx] + solve(prices,1,indx+1,count-1,dp);
            int not_sell = solve(prices,0,indx+1,count,dp);
            return  dp[indx][buy][count] = max(sell,not_sell);
        }
    }
 
// Bottom up tabulation

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int y = 2;
        int z = 3;
         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==0){
                    int taken = -prices[i] + dp[i+1][1][k];
                    int notaken = dp[i+1][0][k];
                    dp[i][j][k] =  max(taken,notaken);
                        }
                    if(j==1){
                        int taken = prices[i] + dp[i+1][0][k-1];
                        int notaken = dp[i+1][1][k];
                        dp[i][j][k] = max(taken,notaken);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};