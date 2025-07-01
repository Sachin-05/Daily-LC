class Solution {
public:
    int possibleStringCount(string word) {
        // a - 1, b - 2, c -4
        int n = word.size();
        int ans=1;

        for(int i=0; i<n;){
            int j= i;

            while(j<n && word[j]==word[i]) j++;

            int count = j-i;

            if(count >=2){
                ans += count - 1;
            }

            i = j;
        }
        return ans;
    }
};
