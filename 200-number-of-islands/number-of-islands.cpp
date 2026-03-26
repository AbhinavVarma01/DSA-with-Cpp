class Solution {
public:


    void dfs(int i, int j, vector<vector<char>>& grid){
        int row = grid.size();
        int cols = grid[0].size();
        if(i<0 || j<0 || i>=row || j>=cols || grid[i][j]=='0') return;

        grid[i][j]='0';

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int row = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid);
                }
            }
        }
        return islands;
    }
};