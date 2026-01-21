class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(r, vector<int> (c, 0));

        int row = 0;
        int col = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(col == c){
                    row++;
                    col = 0;
                }

                if(row >= r) return mat;
        
                res[row][col] = mat[i][j];
                col++;
                
            }
        }

        if(row == r - 1 && col == c) return res;
        else return mat;

    }
};