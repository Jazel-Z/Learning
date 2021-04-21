class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    visit(grid,visited,i,j);
                    ans++;
                }
            }
        }

        return ans;
    }


    void visit(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(grid[i][j] == '1' && !visited[i][j]) visited[i][j] = true;
        else return ;
        if(j+1 < grid[0].size()) visit(grid,visited,i,j+1);
        if(j-1 > -1) visit(grid,visited,i,j-1);
        if(i-1 > -1) visit(grid,visited,i-1,j);
        if(i+1 < grid.size()) visit(grid, visited,i+1,j);
    }
};