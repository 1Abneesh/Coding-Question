class Solution {
public:
    int solve(vector<int>& nums,int k,vector<int> &dp){
        if(k==0){
            return nums[0];
        }
        if(k<0){
            return 0;
        }
        if(dp[k]!=-1){
            return dp[k];
        }
        int steal = solve(nums,k-1,dp);
        int not_steal = nums[k] + solve(nums,k-2,dp);
        return dp[k]=max(steal,not_steal);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp1(nums.size()-1,-1);
        vector<int> dp2(nums.size()-1,-1);
        vector<int> nums1 = nums;
        vector<int> nums2 = nums;
        nums1.erase(nums1.begin()+0);
        nums2.erase(nums2.begin()+nums2.size()-1);
        return max(solve(nums1,nums1.size()-1,dp1),solve(nums2,nums2.size()-1,dp2));   
        return 0;
    }
}; 