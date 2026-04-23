class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // long long n=nums.size();
        // vector <long long> res;

        // for(long long i=0; i<nums.size(); i++){
        //     long long ans=0;
        //     for(long long j=0; j<n; j++){
        //         if(j==i){
        //             continue;
        //         }

        //         if(nums[i]==nums[j]){
        //             ans += abs(i-j);
        //         }
        //     }
        //     res.push_back(ans);
        // }
        // return res;
        long long n = nums.size();
        vector <long long> res(n,0);

        unordered_map<int, vector <long long>> mp;

        for(int i=0; i<n; ++i){
            mp[nums[i]].push_back(i);
        }

        // so we have stored the indexes now;

        for(auto &it: mp){
            vector<long long>& idx = it.second;
            int m = idx.size();

            vector <long long> prefix(m,0);

            prefix[0] = idx[0];

            for(int i=1; i<m; i++){
                prefix[i] = idx[i] + prefix[i-1];
            }

            for(int i=0; i<m; ++i){
                long long left=0, right =0;
                if(i>0){
                    left = i*idx[i] - prefix[i-1];
                }

                if(i <m-1){
                    right = (prefix[m-1]-prefix[i]) - (m-i-1) * idx[i];
                }
                res[idx[i]] = left + right;      
            }
        }
        return res;
    }
};
