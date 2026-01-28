class Solution {
public:
    int numberOfSubstrings(string s) {
        int left =0, right = 0, res = 0;
        int n = s.size();
        unordered_map<char, int> count;
        while(right<n){
            count[s[right]]++;
            while(count['a']> 0 && count['b']>0 && count['c']>0){
                res+=n-right;
                count[s[left]]--;
                left++;
            }
            right++;
        }
        return res;
        
    }
};