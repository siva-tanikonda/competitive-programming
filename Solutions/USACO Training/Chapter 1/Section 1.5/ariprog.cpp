/*
ID: siva.ja1
TASK: ariprog
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const double pi = 3.14159265358979;

int n, m;
bool bs[125001];

int main(){
	IO("ariprog.in", "ariprog.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= m; j++) bs[i * i + j * j] = true;
	vector<int> vec;
	for(int i = 0; i <= m * m * 2; i++)
		if(bs[i]) vec.push_back(i);
	vector<pair<int, int>> res;
	int it = 0;
	for(int i = 0; i < (int)vec.size() - 1; i++)
		for(int j = i + 1; j < (int)vec.size(); j++){
			int cnt = 2, pre = vec[j];
			while(cnt < n){
				it++;
				if(pre + vec[j] - vec[i] > 125000 || !bs[pre + vec[j] - vec[i]]) break;
				cnt++, pre = pre + vec[j] - vec[i];
			}
			if(cnt == n) res.push_back({vec[j] - vec[i], vec[i]});
		}
	sort(res.begin(), res.end());
	for(int i = 0; i < (int)res.size(); i++) cout << res[i].second << " " << res[i].first << "\n";
	if(res.empty()) cout << "NONE\n";
	return 0;
}