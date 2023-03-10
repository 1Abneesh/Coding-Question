//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N,int arr[],int start,int last,vector<vector<int>> &dp){
        if(start==last){
            return 0;
        }
        if(dp[start][last]!=-1){
            return dp[start][last];
        }
        int maxi = INT_MAX;
        for(int k=start;k<=last-1;k++){
            int ans = solve(N,arr,start,k,dp) + solve(N,arr,k+1,last,dp)+ arr[start-1]*arr[k]*arr[last];
            maxi = min(maxi,ans);
        }
        return dp[start][last]= maxi;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int maxi = INT_MAX;
                    for(int k=i;k<=j-1;k++){
                        int ans = dp[i][k] + dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                        maxi = min(maxi,ans);
                    }
                    dp[i][j] = maxi;
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends