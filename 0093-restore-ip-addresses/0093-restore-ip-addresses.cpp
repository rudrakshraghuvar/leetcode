// class Solution {
// public:
//     void backtrack(int i, int dot, int n, string s, string curIP, vector<string>& ans) {
//         if(dot == 3 and i == n) {
//             ans.push_back(curIP);
//             return;
//         }
//         if(dot > 4)
//             return;
        
//         for(int j = i; j < min(i+3, n); j++) {
//             if((stoi(s.substr(i, j-i+1)) < 255) and (i == j or s[i] != '0'))
//                 backtrack(j+1, dot+1, n, s, curIP + s.substr(i, j-i+1) + ".", ans);
//         }
//     }
    
//     vector<string> restoreIpAddresses(string s) {
//         int n = s.size();
//         if(n > 12 or n < 4)
//             return {{}};
        
//         vector<string> ans;
//         backtrack(0, 0, n, s, "", ans);
//         return ans;
//     }
// };

class Solution {
public:
    // Helper function to check if a given string is a valid IP address segment
    bool valid(string temp){
        if(temp.size()>3 || temp.size()==0) return false; // segment length should be between 1 and 3
        if(temp.size()>1 && temp[0]=='0')   return false; // segment should not start with 0, unless it is a single digit
        if(temp.size() && stoi(temp)>255) return false; // segment should not be greater than 255
        return true;
    }

    // Backtracking function to generate all possible IP addresses
    void solve(vector<string>& ans, string output, int ind, string s, int dots){
        if(dots == 3){ // if we have already added 3 dots, check if the remaining segment is valid
            if(valid(s.substr(ind)))
                ans.push_back(output+s.substr(ind));
            return;
        }
        int sz = s.size();
        for(int i=ind;i<min(ind+3, sz);i++){
            if(valid(s.substr(ind, i-ind+1))){
                output.push_back(s[i]);
                output.push_back('.');
                solve(ans, output, i+1, s, dots+1);
                output.pop_back(); //backtrack
            }
        }

    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string res;
        solve(ans, res, 0, s, 0);
        return ans;
    }
};