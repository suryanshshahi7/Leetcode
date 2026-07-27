class Solution {
    string str;
    int n;
    int dp[11][11][2];

    int solve(int idx, int cnt, bool tight) {
        if (idx == n) return cnt;
        if(dp[idx][cnt][tight] != -1) return dp[idx][cnt][tight];
        int ub = tight ? (str[idx] - '0') : 9;

        int ans = 0;

        for (int digit = 0; digit <= ub; digit++) {
            ans += solve(
                idx + 1,
                cnt + (digit == 1),
                tight && (digit == ub)
            );
        }

        return dp[idx][cnt][tight] = ans;
    }

public:
    int countDigitOne(int N) {
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 11; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        str = to_string(N);
        n = str.size();
        return solve(0, 0, true);
    }
};