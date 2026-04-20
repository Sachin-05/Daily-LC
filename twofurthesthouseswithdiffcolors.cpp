class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i=0;
        int j= n-1;

        int ans = -1;

        while(i<j){
            if(colors[i]!=colors[j]){
                ans = max(ans, j-i);
                break;
            }
            j--;
        }
        int ans1=-1;
        int t = n-1;
        int r=0;
        while(r<t){
            if(colors[r]!=colors[t]){
                ans1 = max(ans1, abs(r-t));
            }
            r++;
        }
        return max(ans,ans1);
    }
};
