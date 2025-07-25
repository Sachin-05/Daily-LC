class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1){
            return nums[0];
        }
        int negcnt=0;
      set <int> st;
      for(int i=0; i<sz; ++i){
        if(nums[i]>0){
            st.insert(nums[i]);
        }else{
            negcnt++;
        }
      } 
      int maxi = *max_element(nums.begin(), nums.end());
      if(negcnt==sz){
        return maxi;
      }
      int ans=0;
      for(int x: st){
        ans += x;
      }
      return ans;
    }
};
