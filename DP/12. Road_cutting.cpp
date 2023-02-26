int solve(vector<int> &price, int n, int length,vector<vector<int>> &dp) {
  if (n == 0) {
	  return length*price[0];
  }
  if (dp[n][length] != -1) {
	  return dp[n][length];
  }
    int not_taken = solve(price,n-1,length,dp);
	int taken = INT_MIN;
	int presnt_leght = n+1;
        if (length >= presnt_leght) {
			taken =  price[n] + solve(price, n, length-presnt_leght,dp);
		}
	return dp[n][length] = max(taken,not_taken);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	// return solve(price,n-1,n,dp);
        for (int i = 0; i <= n; i++) {
			dp[0][i] = i*price[0]; 
		}
                for (int i = 1; i < n; i++) {
                  for (int j = 0; j <= n; j++) {
					  int not_taken = dp[i-1][j];
						int taken = INT_MIN;
						int presnt_leght = i+1;
        				if (j >= presnt_leght) {
						taken =  price[i] + dp[i][j-presnt_leght];
											}
						dp[i][j] = max(taken,not_taken);
				  	}
					 
                                }
		return dp[n-1][n];
}


// space optimisation
int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1,0);
	vector<int> current(n+1,0);
        for (int i = 0; i <= n; i++) {
			dp[i] = i*price[0]; 
		}
                for (int i = 1; i < n; i++) {
					
                  for (int j = 0; j <= n; j++) {
					  int not_taken = dp[j];
						int taken = INT_MIN;
						int presnt_leght = i+1;
        				if (j >= presnt_leght) {
						taken =  price[i] + current[j-presnt_leght];
											}
						current[j] = max(taken,not_taken);
				  	}
					  dp = current;
					 
                                }
		return dp[n];
}
