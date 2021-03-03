#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, l[201][202];
bool work[201][201];
string arr[201];

int main(){
	IO("fortmoo.in", "fortmoo.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	bool fnd = false;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] = '0' + arr[i];
		for(int j = 1; j <= m; j++){
			if(arr[i][j] == '.') fnd = true;
			work[i][j] = (arr[i][j] == '.');
		}
	}
	if(!fnd){
		cout << "0\n";
		return 0;
	}
	int ans = 1;
	for(int k = 2; k <= n; k++){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(i + k - 1 > n || arr[i + k - 1][j] == 'X')
					work[i][j] = false;
		for(int i = 1; i <= n - k + 1; i++)
			for(int j = m; j > 0; j--){
				if(work[i][j])
					l[i][j] = max(j, l[i][j + 1]);
				else if(arr[i][j] == 'X' || arr[i + k - 1][j] == 'X')
					l[i][j] = 0;
				else l[i][j] = l[i][j + 1]; 
				if(work[i][j] && l[i][j])
					ans = max(ans, k * (l[i][j] - j + 1));
			}
	}
	cout << ans << '\n';
	return 0;
}