class Solution {
public:
   int solve(vector<int> &arr,int total,int n,int i,int j,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = total - min(solve(arr,total-arr[i],n,i+1,j,dp),solve(arr, total-arr[j],n,i,j-1,dp));  
    }

    bool PredictTheWinner(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += arr[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int player1= solve(arr,total,n,0,n-1,dp);
        int player2 = total-player1;
        return player1>=player2;
    }
};