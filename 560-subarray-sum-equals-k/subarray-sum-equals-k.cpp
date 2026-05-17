class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(); 
        unordered_map<int, int> prefixSumMap;
        int currentPrefixSum = 0, subarrayCount = 0;
        prefixSumMap[0] = 1; 
        for (int i = 0; i < n; i++) {
            currentPrefixSum += nums[i];
            int sumToRemove = currentPrefixSum - k;
            subarrayCount += prefixSumMap[sumToRemove];
            prefixSumMap[currentPrefixSum] += 1;
        }
        return subarrayCount;
    }
};