class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n= tasks.size();
        vector<long long> prefix(n, tasks[0]);
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + tasks[i];

        long long tot = prefix[n-1];
        long long progress = 0;
        vector<int> ans;

        for(int i = 0; i < shifts.size(); i++) {
            int it = shifts[i];
            if(progress+it >= tot) {
                ans.push_back(0);
                progress = 0;
            }
            else {
                progress += it;
                int comp = upper_bound(prefix.begin(), prefix.end(), progress)-prefix.begin();
                ans.push_back(n-comp);
            }
        }

        return ans;
    }
};