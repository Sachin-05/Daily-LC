class Solution {
public:
     void getDistances(const vector<int>& edges, int start, vector<int>& dist) {
        int d = 0;
        vector<bool> visited(edges.size(), false);
        while (start != -1 && !visited[start]) {
            dist[start] = d++;
            visited[start] = true;
            start = edges[start];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        // Compute distances from node1 and node2 to all reachable nodes
        getDistances(edges, node1, dist1);
        getDistances(edges, node2, dist2);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
