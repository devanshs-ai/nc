class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if(s.size()%2!=0){
            return 0;
        }
        for(char ch: s){
            if(st.empty() && (ch==']' || ch=='}' || ch == ')')){
                return false;
            }
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            if(!st.empty() && (ch==')' && st.top()=='(')){
                st.pop();
            }
            else if(!st.empty() && (ch==')' && st.top()!='(')){
                return false;
            }
            if((!st.empty() && ch=='}' && st.top()== '{')){
                st.pop();
            }
            else if((!st.empty() && ch=='}' && st.top()!= '{')){
                return false;
            }
            if((!st.empty() && ch==']'&& st.top()=='[')){
                st.pop();
            }
            else if((!st.empty() && ch==']'&& st.top()!='[')){
                return false;
            }

        }

        return(st.empty());
    }
};
