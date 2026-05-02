class Solution {
public:

    void helper(string current, vector<string>& result, int open, int close){


        if(open == 0 && close == 0){

            result.push_back(current);
            return;
        }

       if(open > 0){
         helper(current + '(', result, open - 1, close);

       }

       if(close > open){
         helper(current + ')', result, open, close - 1);

       }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;

          helper("", result, n, n);
          return result;



        
         

        
        
    }
};
