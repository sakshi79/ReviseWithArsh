// Question link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto x: tokens)
        {
            if(x=="+")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op1+op2);
            }
            else if(x=="-")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2-op1);
            }
            else if(x=="*")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op1*op2);
            }
            else if(x=="/")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2/op1);
            }
            else
                st.push(stoi(x));
        }
        return st.top();
    }
};
