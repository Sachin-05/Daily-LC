class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        // so below is the brute force one now we also have to optimise this as well.

    //     long long n = nums.size();
    //     long long res = 0;
    //     for(long long i=0; i<n-2; ++i){
    //         for(long long j=i+1; j<n-1; ++j){
    //             for (long long k=j+1; k<n; ++k){
    //                 long long temp = (1LL * (nums[i] - nums[j])) * nums[k];
    //                 res = max(res, temp);
    //             }
    //         }
    //     }
    //     return res;


    // let's do int one apss;
    long long n = nums.size();

    // so I want diff and res and maxele

    long maxtriplet = 0, maxdiff = 0, maxele = 0;

    for(long num : nums){
        maxtriplet = max(maxtriplet, maxdiff * num);
        maxdiff = max(maxdiff, maxele - num);
        maxele = max(maxele, num);
    }

    return maxtriplet;
    }
};
