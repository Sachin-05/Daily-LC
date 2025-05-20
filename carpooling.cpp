class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 0 1 2 3 4 5 6 7 8
        //   +2 2.2 2 2 
        int maxi = INT_MIN;

        for(int i=0; i<trips.size(); ++i){
            maxi = max(maxi, trips[i][2]);
        }

        vector <int> diff(maxi+1, 0);

        for(int i=0; i<trips.size(); ++i){
            int l=trips[i][1], r = trips[i][2];

            int value = trips[i][0];

            diff[l] += value;
            diff[r] -= value;
        }

        int coverage = 0;

        for(int i=0; i<=maxi; ++i){
            coverage += diff[i];

            if(coverage > capacity) return false;
        }
        return true;
    }
};
