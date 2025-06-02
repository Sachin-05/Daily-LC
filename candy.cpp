class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();

        vector<int> candies(n,1);

        // left to right pass;
        for(int i=1; i<n; ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        // right to left pass
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        int cnt=0;
        for(auto total : candies){
            cnt += total;
        }
        return cnt;
    }
};
