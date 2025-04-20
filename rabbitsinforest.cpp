class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int,int> mp;

        int result = 0;

        for(auto answer : answers){
            mp[answer]++;
        }

        // so we have the count of map now

        for(auto &[k,v] : mp){
            int groupsize = k+1;
            int numofgroupsneeded = ceil((double)v / groupsize);
            result += numofgroupsneeded * groupsize;
        }

        return result;
    }
};
