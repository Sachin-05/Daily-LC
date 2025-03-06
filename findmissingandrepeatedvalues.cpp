class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n;
        vector <int> count(N+1, 0);
        int repeated = -1, missing = -1;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                count[grid[i][j]]++;
            }
        }

        for(int i=1; i<=N; ++i){
            if(count[i]==2) repeated = i;
            if(count[i]==0) missing = i;
        }

        return {repeated, missing};
    }
};
