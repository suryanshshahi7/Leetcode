class Solution {
    string s;
    int n;
    int dp[11][2][2];
    
    int solve(int idx, bool tight, bool tz, vector<int>& vis) {
        if(idx == n) return 1;
        
        int limit = tight ? (s[idx]-'0') : 9;
        int ans = 0;
        
        for(int i = 0; i <= limit; i++) {
            if(vis[i] == 1) continue;
            if(!tz && i == 0) {
                ans += solve(idx+1, tight && (i == limit), false, vis);
            } 
            else {
                vis[i] = 1;
                ans += solve(idx+1, tight && (i == limit), true, vis);
                vis[i] = 0;
            }
        }
        return ans;
    }
    
public:
    int numDupDigitsAtMostN(int N) {
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        if(N <= 0) return 0;
        s = to_string(N);
        n = s.length();
        vector<int> vis(10, 0);
        return N-solve(0, true, false, vis) + 1;
    }
};