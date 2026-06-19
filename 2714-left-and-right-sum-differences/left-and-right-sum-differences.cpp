class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total+=nums[i];
        }
        int left = 0, right = total;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            right -= nums[i];
            ans.push_back(abs(right-left));
            left+=nums[i];
        }
        return ans;
    }
};