class Solution {
public:
    int numberOfSubstrings(string s) {
        // let solve it first through brute force
    
        // int cnt = 0;
        // for(int i=0; i<s.size()-1; ++i){
        //     unordered_map <char,int> mp;
        //     for(int j=i; j<s.size(); ++j){
        //         mp[s[j]]++;
        //         if(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
        //             cnt += s.size() - j;
        //             break;
        //         }
        //     }
        // }
        // return cnt;

        // so below is the approach that we have did with the two pointers and sliding window technique.
        vector <int> mp = {-1,-1,-1};
        int cnt=0;

        for(int i=0; i<s.size(); ++i){
            mp[s[i]-'a'] = i;

            if(mp[0]!=-1 && mp[1]!=-1 && mp[2]!=-1){
                cnt = cnt + (1+min(mp[0],min(mp[1],mp[2])));
            }
        }
        return cnt;
    }
};
