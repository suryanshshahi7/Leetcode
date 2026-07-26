class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // if all +ve
        int maxi = -1e9;
        int val = nums[n-1] * nums[n-2] * nums[n-3];
        maxi = max(maxi, val);
        // if -ve then we have to take two negatives
        if(nums[1] < 0) val = nums[0] * nums[1] * nums[n-1];
        return max(maxi, val);
    }
};