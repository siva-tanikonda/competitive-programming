/*
ID: siva.ja1
TASK: milk3
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

int a[3];
bool vis[21][21][21];

int main(){
	IO("milk3.in", "milk3.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 3; i++) cin >> a[i];
	queue<vector<int>> que;
	set<int> st;
	que.push({0, 0, a[2]});
	st.insert(a[2]);
	while(!que.empty()){
		vector<int> top = que.front();
		que.pop();
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(i != j){
					vector<int> na = top;
					int tmp = na[j];
					na[j] += min(a[j] - na[j], na[i]);
					na[i] -= min(na[i], a[j] - tmp);
					if(!vis[na[0]][na[1]][na[2]]){
						vis[na[0]][na[1]][na[2]] = true;
						if(na[0] == 0) st.insert(na[2]);
						que.push(na);
					}
				}
	}
	for(auto i = st.begin(); i != st.end(); i++) cout << (i == st.begin() ? "" : " ") << *i;
	cout << "\n";
	return 0;
}