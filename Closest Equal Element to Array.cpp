class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // vector <int> ans;
        // int numssz = nums.size();

        // for(int i=0; i<queries.size();i++){
        //     int check = queries[i]; // 5
        //     int numsvalue = nums[check]; // 3
        //     int mini = INT_MAX;
        //     bool flag = true;
        //     for(int j=0; j<nums.size(); j++){
        //         if((numsvalue==nums[j]) && (check!=j)){
        //             flag = false;
        //             int semians = abs(j-check);
        //             int semiansans = min(semians, abs(numssz-semians));
        //             mini = min(mini, semiansans);
        //         }
        //     }
        //     if(flag==false){
        //         ans.push_back(mini);
        //     }else{
        //         ans.push_back(-1);
        //     }
        // }
        // return ans;

            int n = nums.size();
    
    unordered_map<int, vector<int>> pos;
    
    // Step 1: Store indices for each value
    for (int i = 0; i < n; i++) {
        pos[nums[i]].push_back(i);
    }
    
    vector<int> dist(n, -1);
    
    // Step 2: Process each value group
    for (auto &p : pos) {
        vector<int> &v = p.second;
        int k = v.size();
        
        if (k == 1) continue; // no other same element
        
        for (int i = 0; i < k; i++) {
            int curr = v[i];
            int prev = v[(i - 1 + k) % k];
            int next = v[(i + 1) % k];
            
            int d1 = abs(curr - prev);
            int d2 = abs(curr - next);
            
            // circular distances
            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);
            
            dist[curr] = min(d1, d2);
        }
    }
    
    // Step 3: Answer queries
    vector<int> ans;
    for (int q : queries) {
        ans.push_back(dist[q]);
    }
    
    return ans;
    }
};
