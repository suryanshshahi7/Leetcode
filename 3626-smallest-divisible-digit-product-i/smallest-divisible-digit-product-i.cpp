class Solution {
    int pod(int n) {
        int ans = 1;
        while(n) {
            int val = n%10;
            ans = ans * val;
            n = n/10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        int val = n;
        while(1) {
            int x = pod(val);
            if(x%t == 0) return val;
            val++;
        }
        return -1;
    }
};