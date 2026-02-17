class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r = 0, l = 0;
        int len = 0;
        int minLen = INT_MAX;

        while(r<nums.size()){
            len+= nums[r];

            while(len >= target){
                len-=nums[l];
                minLen = min(minLen, r-l+1);
                l++;
            }
            r++;
        }
        return (minLen==INT_MAX) ? 0 : minLen;
    }
};