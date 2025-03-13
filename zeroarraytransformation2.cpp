class Solution {
public:

    bool cantransform(vector <int>& nums, vector <vector<int>>& queries, int k){
        // TC will be log(Q) + O(N+Q)
        int n = nums.size();
        vector <int> diffarray(n+1);

        for(int i=0; i<k; ++i){
            int start = queries[i][0], end = queries[i][1], value = queries[i][2];
            diffarray[start] += value;
            diffarray[end+1] -= value; 
        }

        // so we have constructed the diff array above
        // now we have to calculate the prefix sum
        int sum=0;
        for(int i=0; i<n; ++i){
            sum += diffarray[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // so at first we are doing this with the helo of binary search
        int n= nums.size();
        int left = 0;
        int right = queries.size();

        // base condition

        if(!cantransform(nums,queries, right)) return -1;

        while(left<=right){
            int mid = left + (right-left) / 2;
            if(cantransform(nums, queries, mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
