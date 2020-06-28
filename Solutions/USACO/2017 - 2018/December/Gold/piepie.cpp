#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, a[200000], b[200000], dst[200000], que[200000];

bool cpa(int x, int y){ return b[x] < b[y]; }

bool cpb(int x, int y){ return a[x] < a[y]; } 

int main(){
	IO("piepie.in", "piepie.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i] >> b[i];
		a[i] *= -1, b[i] *= -1;
		dst[i] = -1;
	}
	int len = 0;
	multiset<int, decltype(&cpa)> sta(&cpa);
	multiset<int, decltype(&cpb)> stb(&cpb);
	for(int i = 0; i < n; i++){
		if(!b[i]) que[len++] = i, dst[i] = 1;
		else sta.insert(i);
		if(!a[n + i]) que[len++] = n + i, dst[n + i] = 1;
		else stb.insert(n + i); 
	}
	int cur = 0;
	while(cur < len){
		int idx = que[cur];
		if(idx < n)
			while(true){
				auto it = stb.lower_bound(idx);
				if(it == stb.end() || a[*it] > a[idx] + m) break;
				dst[*it] = dst[idx] + 1;
				que[len++] = *it;
				stb.erase(it);
			}
		else
			while(true){
				auto it = sta.lower_bound(idx);
				if(it == sta.end() || b[*it] > b[idx] + m) break;
				dst[*it] = dst[idx] + 1;
				que[len++] = *it;
				sta.erase(it);
			}
		cur++;
	}
	for(int i = 0; i < n; i++) cout << dst[i] << "\n";
	return 0;
}
