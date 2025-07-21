class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // {diff{row,col}}
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row==n-1 &&col==m-1)return diff;
            
            for(int i=0; i<4; ++i){
                int nr = dr[i]+row;
                int nc = dc[i]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                    int newEffort = max(abs(heights[row][col]-heights[nr][nc]),diff);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]= newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};