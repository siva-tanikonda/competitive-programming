#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;

int main(){
    IO("notlast.in", "notlast.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<string, int> cnt;
    vector<string> cow = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for(string i : cow) cnt[i] = 0;
    for(int i = 0; i < n; i++){
        string s;
        int add;
        cin >> s >> add, cnt[s] += add;
    }
    map<int, vector<string>> rank;
    for(auto &i : cnt)
        rank[i.second].push_back(i.first);
    auto it = rank.begin();
    it++;
    if(it == rank.end() || (int)(it -> second).size() > 1) cout << "Tie\n";
    else cout << (it -> second).back() << '\n';
    return 0;
}