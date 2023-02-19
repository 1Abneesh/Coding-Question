#include <bits/stdc++.h>
using namespace std;

int solveUtil(int ind, vector<int>& height, int k,vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, k,dp)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind] = mmSteps;
}




int main()
{
    // int n = 4;
    vector<int> a;
    vector<int> dp(2,-1);
    dp[0] = 0;
    a.push_back(100);
    // a.push_back(50);
    a.push_back(100);
    cout<<solveUtil(1,a,10,dp);
    return 0;
}
