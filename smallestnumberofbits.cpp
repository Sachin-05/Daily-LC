class Solution {
public:
    int countofbits(int n){
        int temp = n;
        int res = 0;
        while(temp > 0){
            temp /= 2;
            res++;
        }
        return res;
    }

    int smallestNumber(int n) {
        // calculate the no of bits
        int cnt = countofbits(n);
        int finalans=0;
        for(int i=0; i<cnt; ++i){
            finalans += pow(2, i);
        }
        return finalans;
    }
};
