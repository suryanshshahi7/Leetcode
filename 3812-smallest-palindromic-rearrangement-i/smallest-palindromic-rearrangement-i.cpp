class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);
        
        for(char ch: s) v[ch-'a']++;
        
        string str;
        
        for(int i = 0; i < 26; i++) {
            if(v[i]) {
                while(v[i] > 1) {
                    str.push_back('a'+i);
                    v[i] -= 2;
                }
            }
        }
        bool flag = false;
        for(int i = 0; i < 26; i++) {
            if(v[i] > 0) {
                flag = true;
                str.push_back('a'+i);
            }
        }
        int n = str.size();
        n = n-1;
        if(flag) n = n-1;
        while(n >= 0) {
            str.push_back(str[n]);
            n--;
        }
        return str;
    }
};