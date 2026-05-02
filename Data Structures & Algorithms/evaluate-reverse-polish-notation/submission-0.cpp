class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(string x : tokens){

            if(x == "+" || x == "-" || x == "*" || x == "/"){

                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if(x == "+") st.push(b + a);
                else if(x == "-") st.push(b - a);
                else if(x == "*") st.push(b * a);
                else st.push(b / a);
            }

            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
