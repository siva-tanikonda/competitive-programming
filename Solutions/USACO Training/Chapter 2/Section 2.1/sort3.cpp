/*
ID: siva.ja1
TASK: sort3
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

int n, arr[1000];

int main(){
	IO("sort3.in", "sort3.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cnt[4] = {0, 0, 0, 0};
	for(int i = 0; i < n; i++)
		cin >> arr[i], cnt[arr[i]]++;
	cnt[2] += cnt[1], cnt[3] += cnt[2];
	int rq = 0;
	for(int i = 0; i < n; i++){
		int pos1;
		if(i < cnt[1]) pos1 = 1;
		else if(i < cnt[2]) pos1 = 2;
		else pos1 = 3;
		for(int j = i + 1; j < n; j++){
			int pos2;
			if(j < cnt[1]) pos2 = 1;
			else if(j < cnt[2]) pos2 = 2;
			else pos2 = 3;
			if(arr[i] != pos1 && arr[i] == pos2 && arr[j] == pos1 && arr[j] != pos2){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				rq++;
				break;
			}
		}
		if(arr[i] != pos1){
			for(int j = i + 1; j < n; j++){
				int pos2;
				if(j < cnt[1]) pos2 = 1;
				else if(j < cnt[2]) pos2 = 2;
				else pos2 = 3;
				if(arr[j] == pos1 && arr[j] != pos2){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					rq++;
					break;
				}
			}
		}
	}
	cout << rq << "\n";
	return 0;
}