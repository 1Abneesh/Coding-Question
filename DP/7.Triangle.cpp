 int solve(vector<vector<int>>& triangle,int m,int n,int i,int j){
        if(i == m){
            return triangle[m][j];
        }
        int l = INT_MAX;
        int r = INT_MAX;
        // if(i<m){
        l = triangle[i][j] + solve(triangle,m,n,i+1,j);
        // }
        // if(j<n && i<m){
        r = triangle[i][j] + solve(triangle,m,n,i+1,j+1);
        // }
        return min(l,r);
    }

// bottom up approach ;
 int solve(vector<vector<int>>& triangle,int m,int i,int j,vector<vector<int>>& dp){
        if(i == m){
            return triangle[m][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int l = INT_MAX;
        int r = INT_MAX;
        // if(i<m){
        l = triangle[i][j] + solve(triangle,m,i+1,j,dp);
        // }
        // if(j<n && i<m){
        r = triangle[i][j] + solve(triangle,m,i+1,j+1,dp);
        // }
        return dp[i][j] =  min(l,r);
    }
// space optimistation
int solve(vector<vector<int>>& triangle,int m,int i,int j,vector<int>& dp){
        for(int i=0;i<m;i++){
            dp[i] = triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            vector<int> curr(m,0);
            for(int j=i;j>=0;j--){
                int l = triangle[i][j] + dp[j];
                int r = triangle[i][j] + dp[j+1];
                curr[j] = min(l,r);
            }
            dp = curr;
        }
        return dp[0];
    }