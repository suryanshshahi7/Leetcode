class Solution {
    int solve(int idx, int chance, vector<int>& stoneValue, vector<vector<int>>& dp) {
        int n = stoneValue.size();
        if(idx == n) return 0;
        int sum = 0;
        int ans = -1e9;
        if(dp[idx][chance] != -1) return dp[idx][chance];
        if(chance) {
            for(int i = 0; i < 3 && i+idx < n; i++) {
                sum = sum + stoneValue[i + idx];
                ans = max(ans, sum+solve(i+idx+1, 0, stoneValue, dp));
            }
        }
        else{
            ans = 1e9;
            for(int i = 0; i < 3 && i+idx < n; i++) {
                ans = min(ans, solve(i+idx+1, 1, stoneValue, dp));
            }
        }
        return dp[idx][chance] = ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        int total = 0;
        for(int i: stoneValue) total += i;
        int val = solve(0, 1, stoneValue, dp);
        if(2*val == total) return "Tie";
        if(2*val > total) return "Alice";
        return "Bob";
    }
};


