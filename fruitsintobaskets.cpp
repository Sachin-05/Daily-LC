class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 0 -1
        // 1 - 1
        // 2 - 2
        // I can sort on the basis of max count and second max count return

        unordered_map <int,int> mp;

        // so we now have the count of the frequency and we can do that
        int left = 0, maxfruits = 0;

        for(int r=0; r<fruits.size(); r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                // so we have more than two distinct fruits over here
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxfruits = max(maxfruits, r-left + 1);
        }
        return maxfruits;
    }
};
