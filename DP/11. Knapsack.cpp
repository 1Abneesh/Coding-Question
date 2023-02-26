//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int W, int wt[], int val[], int n,vector<vector<int>> &dp){
        if(n==0){
            if(wt[0]<=W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        int not_taken = solve(W,wt,val,n-1,dp);
        int taken = INT_MIN;
        if(wt[n]<=W){
            taken = val[n] + solve(W-wt[n],wt,val,n-1,dp);
        }
        return dp[n][W] = max(taken,not_taken);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int i = wt[0];i<=W;i++){
           dp[0][i] = val[0];
       }
       for(int i=1;i<n;i++){
           for(int j = 0;j<=W;j++){
               int not_taken = dp[i-1][j];
                int taken = INT_MIN;
                if(wt[i]<=j){
                taken = val[i] + dp[i-1][j-wt[i]];
                    }
                dp[i][j] = max(taken,not_taken);
           }
       }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends