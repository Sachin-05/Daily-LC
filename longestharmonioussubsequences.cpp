class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map <int,int> freq;
        int maxlen=0;

        for(auto num : nums){
            freq[num]++;
        }

        // so we have the frequency count map now in the table
        for(auto& [num,count] : freq){
            if(freq.count(num+1)){
                maxlen = max(maxlen, count + freq[num+1]);
            }
        }
        return maxlen;
    }
};
