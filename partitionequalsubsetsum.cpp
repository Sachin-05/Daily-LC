class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // last idx is our highest one
        int last = nums[n-1];

        // 1 5 5 6 6 11
        //1 2 3 5

        int i = 0, j = n-1;
        int tempansback=nums[j];
        int tempansfront=nums[i];

        while(i < j){
            if(tempansfront < tempansback){
                i++;
                tempansfront += nums[i];
            }else{
                j--;
                tempansback += nums[j];
            }
        }

        if(tempansfront = tempansback){
            return 1;
        }
        return 0;
    }
};
