class Solution {
public:
    int sumofdigits(int n){
        int totalsumofdigit = 0;
        while(n){
            totalsumofdigit += n%10;
            n = n/10;
        }
        return totalsumofdigit;
    }

    int countLargestGroup(int n) {
        // 13 % 10 + 1
        // 21 22
        // 1,10 [2,11,20] [3,12,21]

        unordered_map<int,int> mp;
        int maxsize = 0;
        for(int i=1; i<=n; ++i){
            int sum = sumofdigits(i);
            mp[sum]++;
            maxsize = max(maxsize, mp[sum]);
        }
        
        int res = 0;

        for(auto &group : mp){
            if(group.second == maxsize){
                res++;
            }
        }
        return res;
    }
};
