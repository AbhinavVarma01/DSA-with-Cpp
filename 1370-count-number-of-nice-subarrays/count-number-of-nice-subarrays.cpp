class Solution {
public:

    int helper(vector<int>& nums, int k){
        int r = 0;
        int l = 0;
        int count = 0;
        int sum = 0;
        if(k<0) return 0;
        while(r<nums.size()){
            sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};