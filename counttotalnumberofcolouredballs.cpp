class Solution {
public:
    long long coloredCells(int n) {
        long long res;
        res = pow(n,2) + pow(n-1, 2);
        return res;
    }
};
