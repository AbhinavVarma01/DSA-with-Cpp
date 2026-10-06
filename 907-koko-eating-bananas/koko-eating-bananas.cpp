class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int speed) {
        long long totalHours = 0;
        for(int bananas : piles){
            totalHours += (bananas + speed - 1) / speed;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h){
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low) / 2;
            long long totalHours = hoursNeeded(piles,mid);

            if(totalHours<=h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};