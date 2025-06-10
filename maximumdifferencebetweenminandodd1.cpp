class Solution {
public:
    int maxDifference(string s) {
        vector <int> freq(26,0);

        for(char c : s){
            freq[c-'a']++;
        }

        // now we have the frequency vector for this
        int maxodd = INT_MIN;
        int mineven = INT_MAX;

        for(auto f : freq){
            if(f>0){
                if(f%2==0){
                    // means are f is even then
                    if(f < mineven){
                        mineven = f;
                    }
                }else{
                    if(f > maxodd){
                        maxodd = f;
                    }
                }
            }
        }

        if(mineven==INT_MAX || maxodd==INT_MIN){
            return 0;
        }
        return maxodd - mineven;
    }
};
