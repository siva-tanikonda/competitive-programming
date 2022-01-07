#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, c[100000];

int main(){
	IO("cbarn.in", "cbarn.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		cnt += max(-cnt, c[i] - 1);
	}
	for(int i = 0; i < n; i++){
		if(cnt == 0){
			rotate(c, c + i, c + n);
			break;
		}
		cnt += max(-cnt, c[i] - 1);
	}
	long long cost = 0;
	queue<int> que;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < c[i]; j++) que.push(i);
		long long org = que.front();
		que.pop();
		cost += (org - i) * (org - i);
	}
	cout << cost << "\n";
	return 0;
}