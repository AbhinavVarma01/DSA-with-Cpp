class Solution {
public:

    bool can(long long T, vector<int>& w, long long H){
        long long removed = 0;
        for(long long t : w){
            long long x = T / t;
            long long k = (sqrt(1 + 8*x) - 1) / 2;
            removed += k;
            if(removed >= H) return true;
        }
        return false;
    }

    long long minNumberOfSeconds(int H, vector<int>& w) {
        long long l = 0, r = 1e16;
        long long ans = r;
        while(l <= r){
            long long mid = (l + r) / 2;
            if(can(mid, w, H)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};