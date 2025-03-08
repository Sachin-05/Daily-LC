class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // WBWBBBW 2
        int n = blocks.size();
        int min_ops = k;
        // outer loop is the window slider;
        // why we have equal to because we can have n=k;
        for(int i=0; i<=n-k; ++i){
            int temp=0;
            for(int j=i; j<k+i; ++j){
                if(blocks[j]=='W'){
                    temp++;
                }
            }
            min_ops = min(min_ops, temp);
        }
        return min_ops;
    }
};
