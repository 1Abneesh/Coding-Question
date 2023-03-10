class Solution {
public:
    int solve(int n, vector<int>& cuts,int i,int j){
            if(i>j){
                return 0;
            }
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1] + solve(n,cuts,i,k-1) + solve(n,cuts,k+1,j);
            mini = min(mini,cost);
        }
        return mini;
    }

int f(int i, int j, vector<int> &cuts,vector<vector<int>> &dp){
    
    // base case
    if(i>j)
        return 0;
    
    int mini = INT_MAX;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    for(int ind=i; ind<=j; ind++){
        
        int ans = cuts[j+1] - cuts[i-1] +
                    f(i,ind-1,cuts,dp) +
                    f(ind+1,j,cuts,dp);
        
        mini = min(mini, ans);
        
    }
    
    return dp[i][j] = mini;
}

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),0));
        int c = cuts.size()-2;
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j){continue;}
                int mini = INT_MAX;
                for(int ind=i; ind<=j; ind++){
        
                    int ans = cuts[j+1] - cuts[i-1] +
                               dp[i][ind-1]+
                                dp[ind+1][j];
                    
                    mini = min(mini, ans);
                    
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};