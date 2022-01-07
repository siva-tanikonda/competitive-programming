#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;

void dfs(int vtx, vector<bool> &vis, vector<vector<int>> &adj, vector<set<string>> &arr, vector<set<string>> &spl){
    spl.push_back(arr[vtx]);
    vis[vtx] = true;
    for(int i : adj[vtx])
        if(!vis[i]) dfs(i, vis, adj, arr, spl);
}

bool recurse(vector<set<string>> &arr){
    vector<vector<int>> adj(arr.size());
    for(int i = 0; i < (int)arr.size() - 1; i++)
        for(int j = i + 1; j < (int)arr.size(); j++)
            for(string k : arr[i])
                if(arr[j].find(k) != arr[j].end()){
                    adj[i].push_back(j), adj[j].push_back(i);
                    break;
                }
    vector<bool> vis(arr.size());
    for(int i = 0; i < (int)arr.size(); i++)
        if(!vis[i]){
            vector<set<string>> spl;
            dfs(i, vis, adj, arr, spl);
            bool done = false;
            for(string j : spl.back()){
                bool work = true;
                for(auto &k : spl) work &= (k.find(j) != k.end());
                if(work){
                    vector<set<string>> fin;
                    for(auto k : spl){
                        k.erase(j);
                        if(!k.empty()) fin.push_back(k);
                    }
                    bool res = recurse(fin);
                    if(!res) return false;
                    done = true;
                }
            }
            if(!done) return false;
        }
    return true;
}

int main(){
    IO("evolution.in", "evolution.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<set<string>> a;
    for(int i = 0; i < n; i++){
        int k;
        string val;
        cin >> k;
        if(k == 0) continue;
        else a.push_back(set<string>());
        for(int j = 0; j < k; j++)
            cin >> val, a.back().insert(val);
    }
    cout << (recurse(a) ? "yes\n" : "no\n");
    return 0;
}