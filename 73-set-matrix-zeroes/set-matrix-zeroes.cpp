class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool first_row_has_zero = false;
        bool first_col_has_zero = false;

        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0) first_row_has_zero = true;
        }
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0) first_col_has_zero = true;
        }

        //use first row and col as markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(first_row_has_zero){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(first_col_has_zero){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};