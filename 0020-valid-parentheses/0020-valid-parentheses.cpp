class Solution {
public:
    bool isValid(string s) {
        stack <int> stk;
        
        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[')
                stk.push(i);
            else {
                if((!stk.empty()) && ((stk.top() == '('  and i == ')')
                   || (stk.top() == '{'  and i == '}')
                   || (stk.top() == '['  and i == ']')))
                    stk.pop();
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};