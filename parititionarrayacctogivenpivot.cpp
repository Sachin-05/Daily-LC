class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector <int> small;
        vector <int> equal;
        vector <int> big;
        vector <int> finalres;

for(int i=0; i<n; ++i){
if(nums[i]<pivot){
small.push_back(nums[i]);
}else if(nums[i] > pivot){
big.push_back(nums[i]);
}else{
equal.push_back(nums[i]);
}}

finalres.reserve(small.size() + equal.size() + big.size()); // this is for memory optimization

finalres.insert(finalres.end(), small.begin(), small.end());
finalres.insert(finalres.end(), equal.begin(), equal.end());
finalres.insert(finalres.end(), big.begin(), big.end());

return finalres;
    }
};
