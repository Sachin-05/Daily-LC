class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        // brute force
        int sz = nums.size();
        int res = 0;
        for(int i=0; i<sz-1; ++i){
            for(int j=i+1; j<sz; ++j){
                if((nums[i]==nums[j]) && ((i*j)%k==0)){
                    res++;
                }
            }
        }
        return res;
    }
};
