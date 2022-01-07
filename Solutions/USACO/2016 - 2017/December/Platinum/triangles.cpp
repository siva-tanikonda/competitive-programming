#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

struct point{
    ll x, y;
    point(): x(0), y(0){}
    point(ll _x, ll _y): x(_x), y(_y){}
    bool operator<(const point &b) const{
        return (x != b.x) ? x < b.x : y < b.y;
    }
};

int n, down[300][300], vert[300], ans[298];
bool done[300][300][300], dir[300][300][300];
point a[300];

ll cross(point x, point y){
    return x.x * y.y - x.y * y.x;
}

int main(){
    IO("triangles.in", "triangles.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++){
            point v1(a[j].x - a[i].x, a[j].y - a[i].y);
            point v2(a[i].x - a[j].x, a[i].y - a[j].y);
            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;
                point v3(a[k].x - a[j].x, a[k].y - a[j].y);
                point v4(a[k].x - a[i].x, a[k].y - a[i].y);
                ll d1 = cross(v1, v3);
                ll d2 = cross(v2, v4);
                bool add = (d1 < 0 && d2 > 0 && a[k].x >= a[i].x && a[k].x <= a[j].x);
                down[i][j] += add, down[j][i] += add;
                dir[i][j][k] = (d1 < 0 && d2 > 0);
            }
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            vert[i] += (i != j && a[j].y < a[i].y && a[i].x == a[j].x);
    set<vector<int>> cov;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = 0; k < n; k++){
                if(i == k || k == j || a[k].x > a[j].x || a[k].x < a[i].x) continue;
                vector<int> crd = {i, j, k};
                sort(crd.begin(), crd.end());
                if(done[crd[0]][crd[1]][crd[2]]) continue;
                if(dir[i][j][k])
                    ans[down[i][j] - down[i][k] - down[k][j] + vert[k] - 1]++;
                else
                    ans[down[i][k] + down[k][j] - down[i][j] - vert[k]]++;
                done[crd[0]][crd[1]][crd[2]] = true;
            }
    for(int i = 0; i < n - 2; i++)
        cout << ans[i] << '\n';
    return 0;
}