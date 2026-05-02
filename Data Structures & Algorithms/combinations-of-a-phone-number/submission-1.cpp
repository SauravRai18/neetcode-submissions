class Solution {
public:


    void helper( string& digits, int index, string output, vector<string>& ans,  unordered_map<char, string>& mp ){


        if(index == digits.length()){
            ans.push_back(output);
            return;
        }

        char current = digits[index];
        string letters = mp[current];

        for(char ch : letters){

            helper( digits, index + 1, output + ch, ans, mp );

        }

    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.empty()){
            return ans;
        }

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";


        helper( digits, 0, "", ans, mp );

        return ans;

    }
};
