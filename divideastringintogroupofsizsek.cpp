class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector <string> ans;
        int n = s.length();

        // abc def ghi j

        for(int i=0; i<n; i+=k){
            string temp;
            for(int j=i; j<i+k; j++){
                if(j >= n){
                    temp.push_back(fill);
                    continue;
                }
                temp.push_back(s[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
