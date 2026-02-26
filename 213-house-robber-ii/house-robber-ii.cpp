class Solution {
public:
    int func(int index, vector<int>& nums, vector<int> &dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index] + func(index-2, nums, dp);
        int notpick = 0 + func(index-1, nums, dp);
        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> vct1;
        vector<int> vct2;
        for(int i=0; i<n; i++){
            if(i!=0) vct1.push_back(nums[i]);
            if(i!=n-1) vct2.push_back(nums[i]);
        }
        vector<int> dp1(vct1.size(), -1);
        vector<int> dp2(vct2.size(), -1);
        return max(func(vct1.size()-1,vct1,dp1), func(vct2.size()-1,vct2,dp2));



    }
};