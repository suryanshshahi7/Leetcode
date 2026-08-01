class Solution {
    int dp[501][501];
    int solve(int i, int j, vector<int>& piles) {
        if(i > j) return 0;
        if(i == j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];

        int left = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int right= piles[j] + min(solve(i, j-2, piles), solve(i+1, j-1, piles));

        return dp[i][j] = max(left, right);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        int sum = 0;
        for(int i : piles) sum += i;

        return solve(0, n-1, piles);
    }
};