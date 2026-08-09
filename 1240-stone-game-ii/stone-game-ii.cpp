class Solution {
    int dp[101][2][101];

    int solve(int idx, int chance, int m, vector<int>& piles) {
        int n = piles.size();
        if(idx >= n) return 0;

        if(dp[idx][chance][m] != -1) return dp[idx][chance][m]; // memo

        int ans = 0;
        int val = 0;
        int sum = 0;

        if(chance) {
            for(int i = 0; i < 2*m && (idx + i < n); i++) {
                sum += piles[idx+i];
                val = sum + solve(idx+i+1, !chance, max(i+1, m), piles);
                ans = max(ans, val);
            }
        }
        else{
            ans = 1e9;
            for(int i = 0; i < 2*m && (idx + i < n); i++) {
                sum += piles[idx+i];
                val = solve(idx+i+1, !chance, max(i+1, m), piles);
                ans = min(ans, val);
            }
        }
        return dp[idx][chance][m] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1, piles);
    }
};