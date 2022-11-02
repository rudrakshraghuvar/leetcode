class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> que;
        unordered_set<string> seen;
        seen.insert(start);
        que.push(start);
        
        int ans = 0;
        while(!que.empty()) {
            int nodeInQue = que.size();
            
            for(int i = 0; i < nodeInQue; i++) {
                string node = que.front();
                que.pop();
                
                if(node == end) return ans;
                
                for(char c : "ATGC") {
                    for(int j = 0; j < 8; j++) {
                        string neighbor = node;
                        neighbor[j] = c;
                        if(!seen.count(neighbor) && 
                           find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            que.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};