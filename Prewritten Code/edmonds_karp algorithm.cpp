/*
EDMONDS KARP ALGORITHM
Purpose: It finds the maximum flow in a flow graph
Time Complexity: O(nm^2)
Space Complexity: O(n^2)
*/

template<class T> struct edmonds_karp{
    vector<vector<T>> cap, adj;
    vector<int> par;
    void init(int n){
        cap.resize(n + 1, vector<T>(n + 1));
        adj.resize(n + 1), par.resize(n + 1);
    }
    void addEdge(int u, int v, T val){
        cap[u][v] += val;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    T bfs(int src, int snk){
        fill(par.begin(), par.end(), -1);
        par[src] = -2;
        queue<pair<int, T>> que;
        que.emplace(src, LLONG_MAX);
        while(!que.empty()){
            int vtx = que.front().first;
            T flw = que.front().second;
            que.pop();
            for(int i : adj[vtx])
                if(par[i] == -1 && cap[vtx][i]){
                    par[i] = vtx;
                    T nflw = min(flw, cap[vtx][i]);
                    if(i == snk) return nflw;
                    que.emplace(i, nflw);
                }
        }
        return 0;
    }
    T solve(int src, int snk){
        T flw, res = 0;
        while((bool)(flw = bfs(src, snk))){
            res += flw;
            int vtx = snk;
            while(vtx != src){
                int pre = par[vtx];
                cap[pre][vtx] -= flw;
                cap[vtx][pre] += flw;
                vtx = pre;
            }
        }
        return res;
    }
};