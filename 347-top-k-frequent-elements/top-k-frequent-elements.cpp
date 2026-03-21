class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        for(int x : nums){
            mpp[x]++;
        }

        vector<int> ans;

        while(k--){
            int maxi = 0;
            int element = 0;

            for(auto it : mpp){
                if(it.second > maxi){
                    maxi = it.second;
                    element = it.first;
                }
            }

            ans.push_back(element);
            mpp.erase(element);
        }

        return ans;
    }
};