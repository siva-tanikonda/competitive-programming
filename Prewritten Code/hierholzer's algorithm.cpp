/*
HIERHOLZER'S ALGORITHM
Purpose: It finds an eulerian path/cycle in a graph
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

struct hierholzer{
    int n, m;
    vector<vector<pair<int, int>>> adj;
    vector<vector<pair<int, int>>::iterator> its;
    vector<bool> vis;
    bool dir;
    void init(int _n, bool _dir){
        n = _n, m = 0, dir = _dir;
        adj.resize(n + 1), its.resize(n + 1);
    }
    void addEdge(int a, int b){
        adj[a].emplace_back(b, m);
        if(!dir) adj[b].emplace_back(a, m);
        vis.push_back(false), m++;
    }
    vector<pair<pair<int, int>, int>> solve(int src, int done){
        for(int i = 1; i <= n; i++)
            its[i] = adj[i].begin();
        vector<pair<pair<int, int>, int>> res;
        stack<pair<pair<int, int>, int>> que;
        que.emplace(make_pair(src, -1), -1);
        while(!que.empty()){
            int vtx = que.top().first.first;
            auto &it = its[vtx], end = adj[vtx].end();
            while(it != end && vis[it -> second]) it++;
            if(it == end){
                if(!res.empty() && res.back().first.second != que.top().first.first)
                    return vector<pair<pair<int, int>, int>>();
                res.push_back(que.top()), que.pop();
            }else{
                que.emplace(make_pair(it -> first, vtx), it -> second);
                vis[it -> second] = true;
            }
        }
        if((int)res.size() != m + 1)
            return vector<pair<pair<int, int>, int>>();
        res.pop_back();
        for(auto &i : res) swap(i.first.first, i.first.second);
        reverse(res.begin(), res.end());
        if(done && res.back().first.second != done)
            return vector<pair<pair<int, int>, int>>();
        return res;
    }
};
