class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // so this is we are going to solve with kadanes algo
        int minsum=0, maxsum=0;
        int currmin=0, currmax=0;

        for(int i=0; i<nums.size(); ++i){
            currmax = max(nums[i], currmax + nums[i]);
            maxsum = max(currmax, maxsum);

            currmin = min(nums[i], currmin + nums[i]);
            minsum = min(currmin, minsum);
        }
        return max(abs(maxsum), abs(minsum));
    }
};

// so here we are going to have the absolute sum of spanning over the trees
