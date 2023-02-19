#include<bits/stdc++.h>
using namespace std;

int feb(int n,vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){return dp[n];}
    return dp[n] = feb(n-1,dp) +feb(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int ans = feb(n,dp);
    cout<<ans<<"\n";
    
    return 0;
}