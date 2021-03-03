/*
ID: siva.ja1
TASK: camelot
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, dst[26][30];
int xx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int yy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool cnt[26][30], inc[26][30];
pair<int, int> king;

bool bounds(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void cover(int x, int y){
	inc[x][y] = true;
	for(int i = 0; i < 8; i++){
		int nx = x + xx[i];
		int ny = y + yy[i];
		if(bounds(nx, ny) && !inc[nx][ny] && dst[nx][ny] == dst[x][y] - 1)
			cover(nx, ny);
	}
}

int main(){
	IO("camelot.in", "camelot.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	pair<char, int> rd;
	int num = 0;
	while(cin >> rd.first >> rd.second){
		if(!num) king = {rd.first - 'A', rd.second - 1};
		else cnt[rd.first - 'A'][rd.second - 1] = true;
		num++;
	}
	if(num == 1){
		cout << "0\n";
		return 0;
	}
	long long ans = LLONG_MAX;
	for(int x = 0; x < n; x++)
		for(int y = 0; y < m; y++){
			fill(dst[0], dst[0] + 26 * 30, -1);
			queue<pair<int, int>> que;
			que.push({x, y});
			dst[x][y] = 0;
			while(!que.empty()){
				pair<int, int> vtx = que.front();
				que.pop();
				for(int i = 0; i < 8; i++){
					int nx = vtx.first + xx[i];
					int ny = vtx.second + yy[i];
					if(bounds(nx, ny) && dst[nx][ny] == -1){
						dst[nx][ny] = dst[vtx.first][vtx.second] + 1;
						que.push({nx, ny});
					}
				}
			}
			fill(inc[0], inc[0] + 26 * 30, false);
			long long base = 0;
			bool work = true;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++){
					if(cnt[i][j]){
						base += dst[i][j];
						if(dst[i][j] == -1) work = false;
						if(!inc[i][j]) cover(i, j);
					}
				}
			if(!work) continue;
			int add = INT_MAX;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(inc[i][j])
						add = min(add, max(abs(king.first - i), abs(king.second - j)));
			ans = min(ans, base + add);
		}
	cout << ans << "\n";
	return 0;
}