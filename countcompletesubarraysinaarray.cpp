class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set <int> uniquenum(nums.begin(), nums.end());

        int n = nums.size();
        int res = 0;

        int total = uniquenum.size();

        for(int i=0; i<n; ++i){
            unordered_map <int,int> freq;
            int uniquecnt = 0;
            for(int j=i; j<n; ++j){
            if(++freq[nums[j]]==1){
                uniquecnt++;
            }

            if(uniquecnt == total){
                res++;
            }
            }
        }
        return res;
    }
};
