class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        for(auto &it : st){

            if(st.find(endWord) == st.end()){
                return 0;
            }
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty()){

            auto node = q.front();
             
            q.pop();

            string word = node.first;
            int step = node.second;

            if(word == endWord){
                return step;
            }

            for(int i =0; i<word.size(); i++){

                char temp = word[i];

                for(char ch = 'a'; ch<= 'z'; ch++){  

                    word[i] = ch;

                    if(st.find(word) != st.end()){

                        q.push({word, step + 1});
                        st.erase(word);
                    }

                }

                word[i] = temp;
            }



        }
        return 0;
        
    }
};
