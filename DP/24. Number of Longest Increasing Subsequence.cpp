class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),1);
        int maxi =0;
        int lastindex;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i] == 1+dp[j]){
                        hash[i] +=hash[j];
                    }
                    else if(dp[i]<1+dp[j]){
                            dp[i] = 1+dp[j];
                            hash[i] = hash[j];
                    }
                    
                }
            }
            if(maxi<dp[i]){
            maxi = max(maxi,dp[i]);
            lastindex = i;
            }
        }
        for(auto it:hash){
            cout<<it<<" ";
        }
        int nos =0;
    
    for(int i=0; i<=nums.size()-1; i++){
       if(dp[i]==maxi) nos+=hash[i];
    }
       return nos;
    }
};