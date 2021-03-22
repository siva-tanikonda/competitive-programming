#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
string a[7], b[7];

int main(){
    IO("lineup.in", "lineup.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        string tr;
        for(int j = 0; j < 4; j++) cin >> tr;
        cin >> b[i];
    }
    vector<string> arr = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(arr.begin(), arr.end());
    do{
        bool works = true;
        for(int i = 0; i < n; i++){
            int pa = -1, pb = -1;
            for(int j = 0; j < 8; j++)
                if(a[i] == arr[j]) pa = j;
                else if(b[i] == arr[j]) pb = j;
            works &= (abs(pa - pb) == 1);
        }
        if(works){
            for(string i : arr) cout << i << '\n';
            return 0;
        }
    }while(next_permutation(arr.begin(), arr.end()));
    return 0;
}