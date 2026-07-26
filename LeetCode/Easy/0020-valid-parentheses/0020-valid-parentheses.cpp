class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        // [ { () () } () ]

        stack<char> st;

        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;

                else{
                    char up = st.top();
                    if(up == '(' && s[i] == ')') st.pop();
                    else if(up == '{' && s[i] == '}') st.pop();
                    else if(up == '[' && s[i] == ']') st.pop();
                    else return false;
                }

            }
        }

        // for(int i=0;i<n;i++){
        //     char up = st.top();
        //     if(up == '(' && s[i] == ')') st.pop();
        //     if(up == '{' && s[i] == '}') st.pop();
        //     if(up == '[' && s[i] == ']') st.pop();
        // }

        if(!st.empty()) return false;
        return true;
    }
};