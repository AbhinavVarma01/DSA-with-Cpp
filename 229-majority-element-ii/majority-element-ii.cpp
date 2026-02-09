class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
        }

        for(auto &it : mpp){
            if(it.second > n / 3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};