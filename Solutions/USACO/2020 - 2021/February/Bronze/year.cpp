#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n;
map<string, bool> vis;
map<string, vector<pair<string, int>>> nxt, pre;

int dfs(string cur, int yr, int ans){
    vis[cur] = true;
    if(cur == "Elsie") return ans;
    for(auto &i : nxt[cur])
        if(!vis[i.first]){
            int na = ans;
            if(i.second == yr) na += 12;
            else na += ((i.second - yr) % 12 + 12) % 12;
            int res = dfs(i.first, i.second, na);
            if(res != INT_MAX) return res;
        }
    for(auto &i : pre[cur])
        if(!vis[i.first]){
            int na = ans;
            if(i.second == yr) na -= 12;
            else na -= ((yr - i.second) % 12 + 12) % 12;
            int res = dfs(i.first, i.second, na);
            if(res != INT_MAX) return res;
        }
    return INT_MAX;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<string, int> id;
    id["Ox"] = 0, id["Tiger"] = 1, id["Rabbit"] = 2, id["Dragon"] = 3;
    id["Snake"] = 4, id["Horse"] = 5, id["Goat"] = 6, id["Monkey"] = 7;
    id["Rooster"] = 8, id["Dog"] = 9, id["Pig"] = 10, id["Rat"] = 11;
    for(int i = 0; i < n; i++){
        string a, b, c, d;
        cin >> a >> d >> d >> b >> c >> d >> d >> d;
        if(b == "next") nxt[d].emplace_back(a, id[c]);
        else pre[d].emplace_back(a, id[c]);
    }
    cout << abs(dfs("Bessie", 0, 0)) << '\n';
    return 0;
}