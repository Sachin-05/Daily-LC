class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map <char,int> first, last;

        for(int i=0; i<s.length(); ++i){
            if(!first.count(s[i])) first[s[i]] = i;
            last[s[i]] = i;
        }

        // so we have the first and last occurence of each char of string
        int cnt =0;

        for(char c='a'; c<='z'; c++){
            if(!first.count(c)) continue;
            int l = first[c];
            int r = last[c];

            if(r-l < 2) continue; // no space for the middle char
            unordered_set <char> middlechar;
            for(int i=l+1; i<r; ++i){
                middlechar.insert(s[i]);
            }
            cnt += middlechar.size();
        }
        return cnt;
    }
};
