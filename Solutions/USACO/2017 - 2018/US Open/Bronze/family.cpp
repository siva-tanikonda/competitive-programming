#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
string a, b;
map<string, string> par;

int main(){
    IO("family.in", "family.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;
        par[y] = x;
    }
    vector<string> oa(1, a), ob(1, b);
    while(!par[oa.back()].empty())
        oa.push_back(par[oa.back()]);
    while(!par[ob.back()].empty())
        ob.push_back(par[ob.back()]);
    int pa = -1, pb = -1;
    for(int i = 0; i < (int)oa.size(); i++)
        for(int j = 0; j < (int)ob.size(); j++)
            if(pa == -1 && oa[i] == ob[j]) pa = i, pb = j;
    if(pa == -1) cout << "NOT RELATED\n";
    else if(pa == pb && pa == 1) cout << "SIBLINGS\n";
    else{
        string rel = "";
        if(pa > pb) swap(pa, pb), swap(a, b);
        if(pa > 1){
            cout << "COUSINS\n";
            return 0;
        }
        if(!pa){
            rel = "mother";
            if(pb > 1) rel = "grand-" + rel, pb--;
        }else{
            rel = "aunt";
            int rem = pa;
            pa -= rem, pb -= rem;
        }
        for(int i = 0; i < pb - 1; i++) rel = "great-" + rel;
        cout << a << " is the " << rel << " of " << b << '\n';
    }
    return 0;
}