class Solution {
public:
    int maxDistance(string s, int k) {
        // int ln = s.length();
        // int x=0,y=0;
        // int ans=INT_MIN;
        // for(int i=0; i<ln; ++i){
        //     int xtemp=0, ytemp=0;
        //     if(s[i]=='N'){
        //         ytemp += k;
        //     }else if(s[i]=='E'){
        //         xtemp += k;
        //     }else if(s[i]=='W'){
        //         xtemp -= k;
        //     }else{
        //         ytemp -= k;
        //     }
        //     ans = max(ans, abs(x-xtemp)+abs(y-ytemp));
        // }
        // return ans;

        // above is not the correct way approach
        int n = s.length();
        vector <pair<int,int>> pos(n+1);
        int x=0, y=0;

        pos[0] = {0,0};
        int finaldist=0;

        for(int i=0; i<n; ++i){
            if(s[i]=='N'){
                y++;
            }else if(s[i]=='E'){
                x++;
            }else if(s[i]=='W'){
                x--;
            }else{
                y--;
            }
            int dist = abs(x) + abs(y);

            dist += min(2*k,i+1-dist);

            finaldist = max(finaldist, dist);
        }

        // so we have the position vector now
        return finaldist;
    }
};


// NWSE k=1;
