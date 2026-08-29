class Solution {
public:
vector<bool> vis;
vector<bool> path;
vector<vector<int>> adj;
bool ans = true;
    void dfs(int i){
        path[i] = true;
        vis[i] = true;

        for(int ele : adj[i]){
            if(path[ele]){
                ans = false;
                return;
            }
            if(!vis[ele]) dfs(ele);
        }
        path[i] = false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vis.assign(numCourses,false);
        path.assign(numCourses,false);
        adj.resize(numCourses);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]) dfs(i);
        }
        return ans;
    }
};
