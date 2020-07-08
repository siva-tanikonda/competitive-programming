#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;
long long m, res[1500][10001];

int main(){
	IO("exercise.in", "exercise.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> prm, comp(n + 1);
	for(int i = 2; i <= n; i++)
		if(!comp[i]){
			prm.push_back(i);
			for(int j = 2 * i; j <= n; j += i) comp[j] = 1;
		}
	if(prm.empty()){
		cout << "1\n";
		return 0;
	}
	for(int j = 0; j <= n; j++) res[0][j] = 1;
	for(int i = 1; i <= (int)prm.size(); i++)
		for(int j = 0; j <= n; j++){
			res[i][j] = res[i - 1][j];
			int ppr = prm[i - 1];
			while(ppr <= j){
				res[i][j] = (res[i][j] + (ppr * res[i - 1][j - ppr]) % m) % m;
				ppr *= prm[i - 1];
			}
		}
	cout << res[(int)prm.size()][n] << "\n";
	return 0;
}
