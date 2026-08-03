class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while(left<n && right<m){
            if(g[left]<=s[right]){
                left++;
                right++;
            }
            else right++;
        }
        return left;
    }   
};