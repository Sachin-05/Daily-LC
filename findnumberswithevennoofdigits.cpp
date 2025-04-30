class Solution {
public:
    int numberofdigits(int n){
        int noofd = 0;
        while(n){
            noofd++;
            n = n/10;
        }
        return noofd;
    }

    int findNumbers(vector<int>& nums) {
        int n= nums.size();
        int res=0;

        for(int i=0; i<n; ++i){
            int temp = numberofdigits(nums[i]);

            if(temp%2==0){
                res++;
            }
        }
        return res;
    }
};
