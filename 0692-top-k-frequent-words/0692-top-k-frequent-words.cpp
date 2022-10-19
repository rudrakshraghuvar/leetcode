class Comp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;
        int n = words.size();
        
        for(int i = 0; i < n; i++)
            mp[words[i]]++;
        
        for(auto it : mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
            
        vector<string> ans(k);
        int it = k-1;

        while(pq.size() > 0) {
            ans[it--] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};
    
// see notes section given a link has best explained concept.