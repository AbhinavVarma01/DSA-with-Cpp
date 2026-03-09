class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        if(nums.empty()) return 0;
        int longest = 1;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};