class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // okay 
        sort(nums.begin(), nums.end());
        // TC here is O(N*logN)

        for(int i=0; i<nums.size(); i+=2){
            if(nums[i]!=nums[i+1]){
                return false;
            }
        }
        return true;
    }
};
