class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& vis){
        int size = rooms[room].size();
        for(int i=0; i<size; i++){
            int r = rooms[room][i]; 
            if(!vis[r]){
                vis[r] = true;
                dfs(rooms, r, vis);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        dfs(rooms, 0, vis);
            
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};