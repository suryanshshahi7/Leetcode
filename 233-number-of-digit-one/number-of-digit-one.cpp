class Solution {
    string str;
    int n;
    int dp[11][11][2];
    int solve(int idx, int cnt, bool tight) {
        if(idx == n) return cnt;
        if(dp[idx][cnt][tight] != -1) return dp[idx][cnt][tight];
        int val = 9;
        if(tight) val = min(9, (str[idx]-'0'));
        int ans = 0;
        for(int i = 0; i <= val; i++) {
            ans += solve(idx+1, cnt + (i == 1), tight && (i == val));
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
        string s = to_string(N);
        str = s;
        n = s.size();
        return solve(0, 0, true);
    }
};