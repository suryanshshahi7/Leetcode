class Solution {
    vector<int> sq;
    int dp[100001];
    int solve(int n) {
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];

        bool ans = false;
        for(int i = 0; i < sq.size(); i++) {
            int val = sq[i];
            if(val > n) break;

            ans = solve(n-val);
            if(ans == false) return dp[n] = 1;
        }
        return dp[n] = 0;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> v;
        for(int i = 0; i <= 100000; i++) dp[i] = -1;
        for(int i = 1;; ++i) {
            if(i*i > n) break;
            v.push_back(i*i);
        }
        sq = v;
        return solve(n);
    }
};