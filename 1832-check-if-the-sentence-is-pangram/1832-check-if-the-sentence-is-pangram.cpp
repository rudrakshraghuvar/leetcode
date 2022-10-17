class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26, 0);
        int n = sentence.size();
        
        for(int i = 0; i < n; i++)
            v[sentence[i]-'a']++;
        
        for(int i = 0; i < 26; i++)
            if(v[i] == 0)
                return false;
        
        return true;
    }
};