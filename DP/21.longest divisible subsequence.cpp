vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),0);
        int maxi =0;
        int lastindex;
        for(int i=0;i<nums.size();i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    hash[i] = j;
                    dp[i] = 1+dp[j];
                }
            }
            if(maxi<dp[i]){
            maxi = max(maxi,dp[i]);
            lastindex = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }