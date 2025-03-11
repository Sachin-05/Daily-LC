class Solution {
public:
    int numberOfSubstrings(string s) {
        // let solve it first through brute force
    
        int cnt = 0;
        for(int i=0; i<s.size()-1; ++i){
            unordered_map <char,int> mp;
            for(int j=i; j<s.size(); ++j){
                mp[s[j]]++;
                if(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
