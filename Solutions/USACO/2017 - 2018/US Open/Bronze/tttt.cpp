#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

string a[3];

bool check(int sx, int sy, int dx, int dy, char x, char y){
    bool work = true, ux = false, uy = false;
    for(int i = sx, j = sy, k = 0; k < 3; i += dx, j += dy, k++){
        work &= (a[i][j] == x || a[i][j] == y);
        ux |= (a[i][j] == x), uy |= (a[i][j] == y);
    }
    return (work && ux && uy);
}

int main(){
    IO("tttt.in", "tttt.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 3; i++) cin >> a[i];
    int one = 0, two = 0;
    for(char i = 'A'; i <= 'Z'; i++)
        for(char j = i; j <= 'Z'; j++){
            bool work = check(0, 0, 1, 0, i, j);
            work |= check(0, 1, 1, 0, i, j);
            work |= check(0, 2, 1, 0, i, j);
            work |= check(0, 0, 0, 1, i, j);
            work |= check(1, 0, 0, 1, i, j);
            work |= check(2, 0, 0, 1, i, j);
            work |= check(0, 0, 1, 1, i, j);
            work |= check(0, 2, 1, -1, i, j);
            if(work){
                if(i == j) one++;
                else two++;
            }
        }
    cout << one << '\n' << two << '\n';
    return 0;
}