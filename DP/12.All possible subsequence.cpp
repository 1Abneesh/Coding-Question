class Solution {
public:
// top down
    int solve(string text1, string text2,int index1,int index2,vector<vector<int>> &dp){
        if(index1<0||index2<0){
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + solve(text1,text2,index1-1,index2-1,dp);
        }
        else{
        return dp[index1][index2]= max(solve(text1,text2,index1-1,index2,dp),solve(text1,text2,index1,index2-1,dp));
        }
    }


// bottom up
    int longestCommonSubsequence(string s1, string s2) {
       int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }
};