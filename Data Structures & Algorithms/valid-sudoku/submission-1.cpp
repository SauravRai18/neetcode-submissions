class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string>s;

        for(int i =0; i<9; i++){
            for(int j = 0; j<9; j++){

                char nums = board[i][j];

                if(nums != '.'){

                string row = string(1, nums) + "in row" + to_string(i);
                string col = string(1, nums) + "in col" + to_string(j);
                string grid = string(1, nums) + "in grid" + to_string(i/3) + "grid" + to_string(j/3);

                if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(grid) != s.end()){
                    return false;
                }

                s.insert(row);
                s.insert(col);
                s.insert(grid);

                }


               
            }

            
        }

        return true;

        
        
    }
};
