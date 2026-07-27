class Solution {
    int MOD = 1e9+7;
    vector<long long> fact;
    vector<long long> invFact;

    long long mp(long long b, long long e) {
        long long res = 1;
        while(e) {
            if(e & 1) res = ((long long)res * b) % MOD;
            b = ((long long)b * b) % MOD;
            e >>= 1;
        }
        return res;
    }

    int nCr(long long n, long long r) {
        if(r < 0 || r > n || n < 0) return 0;
        return ((fact[(size_t)n]*invFact[(size_t)n-r]) % MOD *invFact[(size_t)r]) % MOD;
    }
public:
    int countValidSequences(int n, int k) {
        fact.assign(n+1, 1);
        invFact.assign(n+1, 1);
        for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;
        invFact[n] = mp(fact[n], MOD-2);
        for(int i = n-1; i >= 0; i--) invFact[i] = (invFact[i+1] * (i+1)) % MOD;
        long long tot = nCr(n-1, k-1);

        long long x = 0;
        if((n-k) >= 0 && (n-k)%2 == 0) x = nCr((n-k)/2 + k - 1, k-1);

        return (tot-x+MOD)%MOD;
    }
};