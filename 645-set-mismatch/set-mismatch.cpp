class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1,0);
        int repeating = -1;
        int missing = -1;

        for(auto it : nums){
            hash[it]++;
        }

        for(int i=1; i<=n; i++){
            if(hash[i]==2) repeating = i;
            else if(hash[i]==0) missing = i;

            if(repeating!=-1 && missing!= -1) break;
        }

        return {repeating, missing};
    }
};