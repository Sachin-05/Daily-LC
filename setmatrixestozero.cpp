class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <vector<int>> temp = matrix;

        int rows = matrix.size();
        int colm = matrix[0].size();

        for(int i=0; i<rows; ++i){
            for(int j=0; j<colm; ++j){
                if(matrix[i][j]==0){
                    // set rows to zero
                    for(int k=0; k<colm; ++k){
                        temp[i][k] = 0;
                    }

                    // set colm to zero
                    for(int z=0; z<rows; ++z){
                        temp[z][j] = 0;
                    }
                }
            }
        }

        for(int i=0; i<rows; ++i){
            for(int j=0; j<colm; ++j){
                matrix[i][j] = temp[i][j];
            }
        }
    }
};
