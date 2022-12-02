class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26, 0), v2(26, 0), cq1(26, 0), cq2(26, 0);
        int l1 = word1.size(), l2 = word2.size();
        
        for(int i = 0; i < l1; i++)
            v1[word1[i]-'a']++, cq1[word1[i]-'a'] = 1;
        sort(v1.begin(), v1.end());
        
        for(int i = 0; i < l2; i++)
            v2[word2[i]-'a']++, cq2[word2[i]-'a'] = 1;
        sort(v2.begin(), v2.end());
        
        return v1 == v2 and cq1 == cq2;
    }
};