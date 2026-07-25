class Solution {
public:
    int maxProduct(int n) {
        if(n == 10) return 0;
        vector<int> v;
        while(n) {
            int val = n%10;
            n = n/10;
            v.push_back(val);
        }
        sort(v.begin(), v.end());
        int m = v.size();
        return v[m-1]*v[m-2];
    }
};