class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n= nums.size();
          vector <int> res;
        int temp = 0, i=0;

        while(temp < n-1){
            if(nums[i]==nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
            i++;
            temp++;
        }
        for(int i=0; i<n; ++i){
            if(nums[i]!=0){
                res.push_back(nums[i]);
            }
        }
        int tempsz = res.size();
        int zerosz = n - tempsz;

        while(zerosz > 0){
            res.push_back(0);
            zerosz--;
        }
        return res;
    }
};
