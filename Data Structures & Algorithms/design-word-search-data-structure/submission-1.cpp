class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* node = root;

        for(char ch : word){

            int idx = ch - 'a';

            if(node->children[idx] == nullptr){
                node->children[idx] = new TrieNode();     
            }

            node = node->children[idx];     
        }

        node->isEnd = true;     
    }
 

    bool searchHelper(string &word, int pos, TrieNode* node){

        for(int i = pos; i < word.size(); i++){

            char ch = word[i];

            if(ch == '.'){

                for(int j = 0; j < 26; j++){

                    if(node->children[j] != nullptr){
                        if(searchHelper(word, i+1, node->children[j]))
                            return true;
                    }
                }

                return false;
            }
            else{

                int idx = ch - 'a';

                if(node->children[idx] == nullptr){
                    return false;
                }

                node = node->children[idx];
            }
        } 

        return node->isEnd; 
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);   // 🔥 fixed
    }
};
