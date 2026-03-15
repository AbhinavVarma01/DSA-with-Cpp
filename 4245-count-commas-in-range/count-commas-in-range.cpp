class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        if(n>=1000){
            int ans = 1;
            ans+= n-1000;
            return ans;
        }
        return 1;
    }
};