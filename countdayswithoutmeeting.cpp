class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // unordered_map <int,int> mp;

        // for(int i=0; i<meetings.size(); ++i){
        //     for(int j=meetings[i][0]; j<=meetings[i][1]; j++){
        //         mp[j] = 1;
        //     }
        // }
        // sorting the array here
        sort(meetings.begin(), meetings.end());

        int currentstart = -1;
        int currentend = -1;
        int totaldaysavailable =0;

        for(auto meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];

            // now we have the start and end to compare here
            // so let's say that we have the overlapping interval

            if(start <= currentend){
                // extend the range here 
                currentend = max(end, currentend);
            }else{
                // means no overlapping
                if(currentstart!=-1){
                    totaldaysavailable += currentend - currentstart + 1;
                }

                currentstart = start;
                currentend = end;
            }
        }
    
        if(currentstart!=-1){
            totaldaysavailable += currentend - currentstart + 1;
        }

        int nomeetingdays = days - totaldaysavailable;

        return max(0, nomeetingdays);
    }
};
