class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector <vector<bitset<1024>>> dp(m, vector<bitset<1024>> (n) );

        dp[0][0][grid[0][0]] = 1;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){

                if(i==0 && j==0){
                    continue;
                }

                bitset <1024> up; 
                bitset <1024> left;

                if(i>0){
                    up = dp[i-1][j];
                }

                if(j>0){
                    left = dp[i][j-1];
                }

                bitset<1024> combined = left | up;

                for(int xorval=0; xorval<1024; xorval++){
                    if(combined[xorval]){
                        int resultxorval = xorval ^ grid[i][j];
                        dp[i][j][resultxorval] = 1;
                    }
                }
            }
        }

        for(int xorval=0; xorval<1024; xorval++){
            if(dp[m-1][n-1][xorval]){
                return xorval;
            }
        }
        return -1;
    }
};
