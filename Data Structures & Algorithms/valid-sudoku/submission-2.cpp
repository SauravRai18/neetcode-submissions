class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


      unordered_set<string> st;

      int n = board.size();
      int m = board[0].size();

      for(int i = 0; i<n; i++){

         for(int j =0; j<m; j++){

            char nums = board[i][j];

            if(nums != '.'){

               string rowcheck = string(1 , nums) + "int row" + to_string(i);
               string colcheck = string(1 , nums) + "int col" + to_string(j);
               string gridcheck = string(1 , nums) + "int grid" + to_string(i/3) + "box" + to_string(j/3);

               if(st.find(rowcheck) != st.end() || 
               st.find(colcheck) != st.end() || 
               st.find(gridcheck) != st.end()){
                  return false;
               }

               st.insert(rowcheck);
               st.insert(colcheck);
               st.insert(gridcheck);
               
            }

         }
      }

      return true;
        
    }
};
