class Solution {
public:


    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<vector<int>> sol(row, vector<int> (cols));
        for(int i=0; i<row; i++){
            for(int j=0; j<cols; j++){
                sol[i][j] = grid[i][j];
                if(i>0) sol[i][j] += sol[i-1][j];
                if(j>0) sol[i][j] += sol[i][j-1];
                if(i>0 && j>0) sol[i][j] -= sol[i-1][j-1];

                if(sol[i][j]<=k) count++;
            }
        }
        return count;
    }
};