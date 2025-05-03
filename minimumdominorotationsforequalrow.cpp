class Solution {
public:
    int rotatematching(int number, vector<int>& first, vector<int>& second){
        int count = 0;
        for(int i=0; i<first.size(); ++i){
            if(first[i]==number) continue;
            else if(second[i] == number) count++;
            else return INT_MAX;
        }
        return count;
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int minrotations = INT_MAX;

       for(int i=1; i<=6; ++i){
        int count_tops = rotatematching(i, tops, bottoms);
        int count_bottom = INT_MAX;

        if(count_tops!=INT_MAX){
            count_bottom = rotatematching(i, bottoms, tops);
        }

        minrotations = min(minrotations, min(count_tops, count_bottom));
       }
       return minrotations==INT_MAX ? -1 : minrotations;
    }
};
