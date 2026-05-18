class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end()); 
        int low = 0;
        int high = nums1.size()-1;
        while(low<=high){
            if(nums1.size() %2!=0){
                int mid = low + (high - low)/2; 
                double median = nums1[mid];
                return median;
            }
            else{
                int mid = low + (high - low)/2;
                double median = (nums1[mid] + nums1[mid+1]) / 2.0;
                return median;
            }
        }
        return -1;

    }
};