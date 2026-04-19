class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN;

        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=i; j<nums2.size(); j++){
        //         if((i<=j) && (nums1[i]<=nums2[j])){
        //             int diff = j-i;
        //             ans = max(ans, diff);
        //         }
        //     }
        // }
        // return (ans==INT_MIN) ? 0 : ans;

        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(i>j){
                j=i;
            }
            
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j-i);
                j++;
            }else{
                i++;
            }
        }
        return (ans==INT_MIN) ? 0 : ans;
    }
};
