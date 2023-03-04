class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int notaken = solve(s,t,i-1,j,dp);
        int taken = 0;
        if(s[i] == t[j]){
        taken= solve(s,t,i-1,j-1,dp);
        }
        return dp[i][j]= taken + notaken;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return solve(s,t,s.size()-1,t.size()-1,dp);
        for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            int notaken = dp[i-1][j];
            int taken = 0;
            if(s[i-1]==t[j-1]){
                taken = dp[i-1][j-1];
            }
            dp[i][j] = taken+notaken;
        }
    }
    return dp[n][m];
    }
};