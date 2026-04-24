class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char,int> mp;

        for(char it : moves){
            mp[it]++;
        }

        int left = mp['L'];
        int right = mp['R'];
        int blank = mp['_'];

        return blank + abs(right-left);
    }
};
