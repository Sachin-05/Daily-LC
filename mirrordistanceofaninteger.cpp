class Solution {
public:
    int reversenum(int x){
        int rev=0;
        while(x>0){
            rev = rev*10 + (x%10);
            x = x/10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        int rev = reversenum(n);

        int ans = abs(n - rev);

        return ans;
    }
};
