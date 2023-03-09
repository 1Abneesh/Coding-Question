int LongestBitonicSequence(vector<int>nums)
	{
        vector<int> dpf(nums.size(),1);
        vector<int> dpl(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dpf[i] = max(dpf[i],1+dpf[j]);
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dpl[i] = max(dpl[i],1+dpl[j]);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<dpl.size();i++){
            maxi = max(dpl[i]+dpf[i]-1,maxi);
        }
        return maxi;
	}