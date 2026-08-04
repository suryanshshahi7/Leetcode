class Solution {
public:
    vector<int> v;
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i : nums) st.insert(i);
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        for(int i = mini; i < maxi; i++) if(st.find(i) == st.end()) v.push_back(i);
        return v;
    }
};