class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int maxi = -1, ans = 1;
        for(int i : nums) maxi = max(maxi, i);
        while(maxi) {
            ans *= 2;
            maxi /= 2;
        }
        return ans;
    }
};

// 3 1 0
// 1 2 4

// 5 2 1 0
// 1 2 4 8

// 4 2 1 0
// 1 2 4 8