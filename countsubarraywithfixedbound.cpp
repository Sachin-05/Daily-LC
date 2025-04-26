class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
       int n = nums.size();
       long long ans = 0;

       int lastminK = -1;
       int lastmaxK = -1;
       int lastinvalid = -1;

       for(int i =0; i<n; ++i){
        if(nums[i] > maxK || nums[i] < minK ){
            lastinvalid = i;
        }

        if(nums[i] == minK){
            lastminK = i;
        }

        if(nums[i] == maxK){
            lastmaxK = i;
        }

        int validStart = min(lastminK, lastmaxK);
        if(validStart > lastinvalid){
            ans += validStart - lastinvalid;
        }

       }
       return ans;
    }
};
