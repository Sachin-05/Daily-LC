class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();

        if(n<3){
            return 0;
        }

        int res = 0;

        for(int i=0; i<=n-3; ++i){
            int first = nums[i];
            int second = nums[i+1];
            int third = nums[i+2];

            if((first + third)*2 == second){
                res++;
            }
        }
        return res;
    }
};
