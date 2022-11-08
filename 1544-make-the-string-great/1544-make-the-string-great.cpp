class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> stck;
        stck.push(s[0]);
        for(int i = 1; i < s.length(); i++) {
            char c;
            if(!stck.empty())
                c = stck.top();
            if(!stck.empty() && abs(c-s[i]) == 32)
                stck.pop();
            else 
                stck.push(s[i]);
        }
        
        while(!stck.empty()) {
            ans = stck.top() + ans;
            stck.pop();
        }
        
        return ans;
    }
};