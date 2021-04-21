class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max = 0;
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        vector<vector<int>> val(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix[0].size();j++){
                int tmp = dfs(matrix,visited,val,i,j);
                if(tmp > max) max = tmp;
            }
        }
        return max;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& val,int i, int j){
        int ret = 0;
        if(val[i][j] != -1) return val[i][j];
        visited[i][j] = true;

        if(i+1 < matrix.size() && !visited[i+1][j] && matrix[i+1][j] > matrix[i][j]){
            ret = dfs(matrix,visited,val,i+1,j) > ret ? dfs(matrix,visited,val,i+1,j) : ret;
        }
        if(i-1 > -1 && !visited[i-1][j] && matrix[i-1][j] > matrix[i][j]){
            ret = dfs(matrix,visited,val,i-1,j) > ret ? dfs(matrix,visited,val,i-1,j) : ret;
        }
        if(j+1 < matrix[0].size() && !visited[i][j+1] && matrix[i][j+1] > matrix[i][j]){
            ret = dfs(matrix,visited,val,i,j+1) > ret ? dfs(matrix,visited,val,i,j+1) : ret;
        }
        if(j-1 > -1 && !visited[i][j-1] && matrix[i][j-1] > matrix[i][j]){
            ret = dfs(matrix,visited,val,i,j-1) > ret ? dfs(matrix,visited,val,i,j-1) : ret;
        }
        visited[i][j] = false;
        val[i][j] = 1+ret;

        return 1+ret;
    }
};


