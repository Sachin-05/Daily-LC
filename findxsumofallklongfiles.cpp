class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        if(k>n) return {};
        vector <int> ans;
        ans.reserve(n-k+1);

        for(int i=0; i+k<=n; ++i){
            int freq[51] = {0};
            for(int j=i; j<i+k; ++j){
                freq[nums[j]]++;
            }

            // we have the freq count;
            vector<pair <int,int>> pp;
            pp.reserve(50);
            for(int i=1; i<=50; ++i){
                if(freq[i]>0) pp.emplace_back(freq[i], i);
            }
            // so we have vector of pairs now;

            sort(pp.begin(), pp.end(), [](const pair<int,int>&a, const pair<int,int> &b){
            if(a.first!=b.first) return a.first > b.first;
            return a.second > b.second;
        });

        int take = min(x, (int) pp.size());
        int sum = 0;
        for(int t=0; t<take; ++t){
            sum += pp[t].first * pp[t].second;
        }
        ans.push_back(sum);
    }
    return ans;
    }
};
