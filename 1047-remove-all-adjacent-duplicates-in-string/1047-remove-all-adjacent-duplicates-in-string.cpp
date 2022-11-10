class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        stk.push(s[0]);
        
        for(int i = 1; i < s.length(); i++) {
            char c;
            if(!stk.empty())
                c = stk.top();
            if(!stk.empty() && c == s[i])
                stk.pop();
            else
                stk.push(s[i]);
        }
        
        string ans = "";
        
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};