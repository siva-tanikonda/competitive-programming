#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

vector<int> b[2], pos;

void recursion(int it, vector<int> b1, vector<int> b2, int tank1, int tank2){
    if(it == 2 || it == 4){
        for(int i = 0; i < (int)b1.size(); i++){
            vector<int> copy1 = b1;
            vector<int> copy2 = b2;
            int value = copy1[i];
            copy1.erase(copy1.begin() + i);
            copy2.push_back(value);
            recursion(it + 1, copy1, copy2, tank1 - value, tank2 + value);
        }
    }else if(it == 3 || it == 5){
        for(int i = 0; i < (int)b2.size(); i++){
            vector<int> copy1 = b1;
            vector<int> copy2 = b2;
            int value = copy2[i];
            copy2.erase(copy2.begin() + i);
            copy1.push_back(value);
            recursion(it + 1, copy1, copy2, tank1 + value, tank2 - value);
        }
    }else pos.push_back(tank1);
}

int getTotal(){
    int total = 0;
    for(int i = 0; i < (int)pos.size(); i++){
        if(pos[i] != -1) total++;
        for(int j = i + 1; j < (int)pos.size(); j++)
            if(pos[i] == pos[j]) pos[j] = -1;
    }
    return total;
}

int solve(){
    recursion(2, b[0], b[1], 1000, 1000);
    return getTotal();
}

int main(){
    IO("backforth.in", "backforth.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 10; i++){
        int input;
        cin >> input;
        b[0].push_back(input);
    }
    for(int i = 0; i < 10; i++){
        int input;
        cin >> input;
        b[1].push_back(input);
    }
    cout << solve() << endl;
    return 0;
}