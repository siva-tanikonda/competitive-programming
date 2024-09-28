/*
MO'S ALGORITHM
Purpose: Takes a list of Q range queries on an array of length N and answers them offline
Time Complexity: O(sqrt(N)(N+Q))
Space Complexity: O(N+Q)
*/

template<typename T>
vector<T> mo(vector<pair<int, int>> que, function<T(int)> solve, function<void(int)> add, function<void(int)> sub) {
    constexpr int BS = 500; // Change if you want to optimize runtime
    vector<pair<pair<int, int>, int>> qord;
    for (int i = 0; i < (int)que.size(); i++)
        qord.emplace_back(que[i], i);
    sort(qord.begin(), qord.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
        return make_pair(a.first.first / BS, a.first.second) < make_pair(b.first.first / BS, b.first.second);
    });
    vector<T> res(que.size());
    int l = 0, r = -1;
    for (const pair<pair<int, int>, int> &q : qord) {
        while (q.first.first > l) sub(l++);
        while (q.first.first < l) add(--l);
        while (q.first.second > r) add(++r);
        while (q.first.second < r) sub(r--);
        res[q.second] = solve(q.second);
    }
    return res;
}
