class Solution {
    vector<int> v;
    int dp[501][501];
    int solve(int i, int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int tot = 0;
        for(int x = i; x <= j; x++) tot += v[x];

        int ans = 0;
        int sum = 0;
        for(int x = i; x <= j; x++) {
            sum += v[x];
            int val = tot - sum;
            
            if(sum < val) ans = max(ans, sum + solve(i, x));
            if(sum > val) ans = max(ans, val + solve(x+1, j));
            if(sum == val){
                int left = sum + solve(i, x);
                int right = sum + solve(x+1, j);
                ans = max(left, right);
            }
        }
        return dp[i][j] = ans;
    }
public:
    int stoneGameV(vector<int>& stoneValues) {
        v = stoneValues;
        int n = v.size();
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, n-1);
    }
};