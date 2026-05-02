struct TrieNode {
    TrieNode* children[26];
    string word;  // store word at the end node
    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Step 1: Build Trie from the words
        TrieNode* root = buildTrie(words);
        vector<string> res;

        // Step 2: DFS from every cell
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

private:
    // Build a Trie from the list of words
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string &w : words) {
            TrieNode* node = root;
            for(char c : w) {
                int idx = c - 'a';
                if(!node->children[idx]) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w;  // mark end of word
        }
        return root;
    }

    // DFS helper
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res) {
        char c = board[i][j];
        if(c == '#' || !node->children[c - 'a']) return; // visited or no path in Trie

        node = node->children[c - 'a'];
        if(!node->word.empty()) { // found a word
            res.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto &d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if(ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size())
                dfs(board, ni, nj, node, res);
        }
        board[i][j] = c; // restore original char
    }
};
