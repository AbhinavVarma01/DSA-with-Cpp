class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        int small = INT_MAX;
        int secSmall = INT_MAX;
        for(int i=1; i<n; i++){
            if(nums[i]<small){
                secSmall = small;
                small = nums[i];
            }

            else if(nums[i]<secSmall) secSmall = nums[i];
            }
        
        return first + small + secSmall;
    }
};