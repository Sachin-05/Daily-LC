class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n =nums.size();

        vector <int> temp(n+1);

        for(int i=0; i<n; ++i){
            temp[i] = nums[i];
        }

        temp[n] = nums[0];

        int ans = INT_MIN;

        for(int i=1; i<n+1; ++i){
            int diff = abs(temp[i-1]-temp[i]);
            ans = max(diff, ans);
        }
        return ans;
    }
};
