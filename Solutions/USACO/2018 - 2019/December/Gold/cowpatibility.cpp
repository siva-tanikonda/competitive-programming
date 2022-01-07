#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;

struct subset{ int n, a[5]; };
bool operator<(const subset &a, const subset &b){
	for(int i = 0; i < 5; i++){
		if(a.a[i] < b.a[i]) return true;
		else if(a.a[i] > b.a[i]) return false;
	}
	return false;
}

subset generate(int a[], int req){
	subset arr = {0, {0, 0, 0, 0, 0}};
	for(int i = 0; i < 5; i++)
		if((1 << i) & req) arr.a[arr.n++] = a[i];
	return arr;
}

int main(){
	IO("cowpatibility.in", "cowpatibility.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	map<subset, long long> mp;
	int arr[5];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++) cin >> arr[j];
		sort(arr, arr + 5);
		for(int j = 1; j < 32; j++) mp[generate(arr, j)]++; 
	}
	int mod[] = {-1, 1, -1, 1, -1, 1};
	long long sum = ((long long)n * (n - 1)) / 2;
	for(auto &i : mp) sum -= mod[i.first.n] * (i.second * (i.second - 1)) / 2; 
	cout << sum << "\n";
	return 0;
}