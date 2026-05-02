class Solution {
public:

    int solve(string& word1, string& word2, int i, int j, int m, int n, vector<vector<int>>& dp){

        if(j >= n){
            return m - i;
        }

        if(i >= m){
            return n - j;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){

            return dp[i][j] = solve(word1, word2, i + 1, j + 1, m, n, dp);
        }

        int ins = solve(word1, word2, i, j + 1, m, n, dp);

        int del = solve(word1, word2, i + 1, j , m, n, dp);

        int rep = solve(word1, word2, i + 1, j + 1, m, n, dp);


        return dp[i][j] = 1 + min({ins, del, rep});


    }


    int minDistance(string word1, string word2) {

        int m = word1.size();

        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(word1, word2, 0, 0, m, n, dp);
        
    }
};
