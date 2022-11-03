class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        
        for(int i = 0; i < words.size(); i++)
            mp[words[i]]++;
        
        int ans = 0, flag = 0;
        for(auto m : mp) {
            string word = m.first;
            int cnt = m.second;
            
            if(word[0] == word[1]) {
                if(cnt % 2 == 0)
                    ans += cnt;
                else {
                    ans += cnt-1;
                    flag = 1;
                }
            }
            else if(word[0] < word[1] && mp.count({word[1], word[0]}))
                ans += 2 * min(cnt, mp[{word[1], word[0]}]);
        }
        
        if(flag)
                ans++;
            
            return 2 * ans;
    }
};