#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
char a[1000][1000];
int vis[1000][1000];
int ra, rp = 1000000000;

int bounds(int i, int j){
    int sum = 0;
    sum += ((i + 1 < n && a[i + 1][j] == '.') || i + 1 == n);
    sum += ((i - 1 > - 1 && a[i - 1][j] == '.') || i - 1 == -1);
    sum += ((j + 1 < n && a[i][j + 1] == '.') || j + 1 == n);
    sum += ((j - 1 > - 1 && a[i][j - 1] == '.') || j - 1 == -1);
    return sum;
}

void island(vector<int> &y, vector<int> &x, int i, int j){
    if(i < n && i > -1 && j > -1 && j < n && a[i][j] == '#' && vis[i][j] == 0){
        vis[i][j] = 1;
        y.push_back(i), x.push_back(j);
        island(y, x, i + 1, j), island(y, x, i - 1, j);
        island(y, x, i, j + 1), island(y, x, i, j - 1);
    }
}

int perimeter(vector<int> &y, vector<int> &x){
    int sum = 0;
    for(int i = 0; i < x.size(); i++)
        sum += bounds(y[i], x[i]);
    return sum;
}

int main(){
    IO("perimeter.in", "perimeter.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n ; j++)
            if(vis[i][j] == 0 && a[i][j] == '#'){
                vector<int> x, y;
                island(y, x, i, j);
                int area = (int)x.size();
                if(area >= ra){
                    int border = perimeter(y, x);
                    if(area > ra || (area == ra && border < rp))
                        ra = area, rp = border;
                }
            }
    cout << ra << " " << rp << '\n';
    return 0;
}