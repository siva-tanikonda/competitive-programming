/*
ID: siva.ja1
TASK: friday
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

int n, res[7], val[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	IO("friday.in", "friday.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int day = 1, yr = 1900, mnt = 0, week = 2;
	while(yr < 1900 + n){
		if(day == 13) res[week]++;
		day++, week++;
		if(week > 6) week = 0;
		if(mnt != 1 && day > val[mnt]) mnt++, day = 1;
		else if(mnt == 1 && ((yr % 4 == 0 && yr % 100) || (yr % 400 == 0)) && day > 29) mnt++, day = 1;
		else if(mnt == 1 && !((yr % 4 == 0 && yr % 100) || (yr % 400 == 0)) && day > 28) mnt++, day = 1;
		if(mnt > 11) yr++, mnt = 0;   
	}
	for(int i = 0; i < 7; i++) cout << res[i] << ((i == 6) ? '\n' : ' ');
	return 0;
}