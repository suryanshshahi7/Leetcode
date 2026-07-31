class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a, vector<vector<int>>& b) {
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;
        vector<vector<int>> result;

        while(i < m || j < n) {
            long long t = 0;
            if(i < m && j < n) t = min(a[i][0], b[j][0]);
            else if(i < a.size()) t = a[i][0];
            else t = b[j][0];

            long long x = 0;
            if(i < m) {
                if(a[i][0] == t) {
                    x = a[i][1];
                    i++;
                }
                else x = a[i][1];
            }

            long long y = 0;
            if(j < n) {
                if(b[j][0] == t) {
                    y = b[j][1];
                    j++;
                }
                else y = b[j][1];
            }
            result.push_back({(int)t, (int)(x+y)});
        }
        return result;
    }
};