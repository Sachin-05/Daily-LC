class Solution {
public:
    int reversenum(int x){
        int rev =0;
        while(x>0){
            rev = rev*10 + (x%10);
            x = x/10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map <int,int> lastseen;
        int ans = INT_MAX;

        for(int j=0; j<nums.size(); j++){
            int rev = reversenum(nums[j]);

            if(lastseen.count(nums[j])){
                ans = min(ans, j-lastseen[nums[j]]);
            }

            lastseen[rev] = j;
        }

        return (ans==INT_MAX) ? -1 : ans;
    }
};
