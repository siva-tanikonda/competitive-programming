#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
string s;

int main(){
    IO("whereami.in", "whereami.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        map<string, bool> cov;
        bool work = true;
        for(int j = 0; j <= n - i; j++){
            string str = s.substr(j, i);
            if(!cov[str]) cov[str] = true;
            else work = false;
        }
        if(work){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}