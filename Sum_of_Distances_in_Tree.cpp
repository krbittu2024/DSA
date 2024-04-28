class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // jai shree ram
        
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans(n, 0); 
        vector<int> count(n, 1); 
        
        dfs(0, -1, graph, count, ans); 
        
        dfs2(0, -1, graph, count, ans, n); 
        
        return ans;
    }
    
   
    void dfs(int node, int parent, const vector<vector<int>>& graph, vector<int>& count, vector<int>& ans) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node, graph, count, ans);
                count[node] += count[child];
                ans[node] += ans[child] + count[child]; 
            }
        }
    }
    

    void dfs2(int node, int parent, const vector<vector<int>>& graph, const vector<int>& count, vector<int>& ans, int n) {
        for (int child : graph[node]) {
            if (child != parent) {
               
                ans[child] = ans[node] - count[child] + (n - count[child]);
                dfs2(child, node, graph, count, ans, n); 
            }
        }
    }
};
