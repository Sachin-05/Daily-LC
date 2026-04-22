class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
            int qsz = queries.size();
            int dsz = dictionary.size();

            vector<string> result;

            for( auto q : queries){
                bool found = false;
                for(auto d : dictionary){
                    int diff=0;

                    for(int i=0; i<q.size(); i++){
                    if(q[i]!=d[i]){
                        diff++;
                    }
                    }

                    if(diff<=2){
                        found = true;
                        break;
                    }
                }
                if(found){
                    result.push_back(q);
                }
            }
            return result;
    }
};
