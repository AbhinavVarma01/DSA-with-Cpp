class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        int n = g.size();
        int m = s.size();
        int left = 0;
        int right = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(left<n && right<m){
            if(g[left]<=s[right]){
                left++;
                right++;
            }
            else{
                right++;
            }
        }
        return left;
    }   
};