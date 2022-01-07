/*
TWO-DIMENSIONAL SEGMENT TREE
Purpose: This is a segment tree that runs on a 2D array
Time Complexity: [Build]O(n^2) [Update]O(lg^2(n)) [Query]O(lg^2(n))
Space Complexity: O(n^2)
*/

template<class T> struct two_dimensional_segment_tree{
    vector<vector<T>> arr;
    int n, m;
    void init(int _n, int _m){
        n = _n, m = _m;
        arr.resize(n * 4, vector<T>(m * 4));
    }
    void init(vector<vector<T>> &lst){
        n = (int)lst.size(), m = (int)lst[0].size();
        arr.resize(n * 4, vector<T>(m * 4));
        buildX(1, 0, n - 1, lst);
    }
    void buildY(int xv, int xtl, int xtr, int yv, int ytl, int ytr, vector<vector<T>> &lst){
        if(ytl == ytr){
            if(xtl == xtr) arr[xv][yv] = lst[xtl][ytl];
            else arr[xv][yv] = arr[xv * 2][yv] + arr[xv * 2 + 1][yv];
        }else{
            int mid = ytl + (ytr - ytl) / 2;
            buildY(xv, xtl, xtr, yv * 2, ytl, mid, lst);
            buildY(xv, xtl, xtr, yv * 2 + 1, mid + 1, ytr, lst);
            arr[xv][yv] = arr[xv][yv * 2] + arr[xv][yv * 2 + 1];
        }
    }
    void buildX(int xv, int xtl, int xtr, vector<vector<T>> &lst){
        if(xtl != xtr){
            int mid = xtl + (xtr - xtl) / 2;
            buildX(xv * 2, xtl, mid, lst);
            buildX(xv * 2 + 1, mid + 1, xtr, lst);
        }
        buildY(xv, xtl, xtr, 1, 0, m - 1, lst);
    }
    void update(int x, int y, T val){
        updateX(1, 0, n - 1, x, y, val);
    }
    void updateY(int xv, int xtl, int xtr, int yv, int ytl, int ytr, int x, int y, T val){
        if(ytl == ytr){
            if(xtl == xtr) arr[xv][yv] = val;
            else arr[xv][yv] = arr[xv * 2][yv] + arr[xv * 2 + 1][yv];
        }else{
            int mid = ytl + (ytr - ytl) / 2;
            if(y <= mid) updateY(xv, xtl, xtr, yv * 2, ytl, mid, x, y, val);
            else updateY(xv, xtl, xtr, yv * 2 + 1, mid + 1, ytr, x, y, val);
            arr[xv][yv] = arr[xv][yv * 2] + arr[xv][yv * 2 + 1];
        }
    }
    void updateX(int xv, int xtl, int xtr, int x, int y, T val){
        if(xtl != xtr){
            int mid = xtl + (xtr - xtl) / 2;
            if(x <= mid) updateX(xv * 2, xtl, mid, x, y, val);
            else updateX(xv * 2 + 1, mid + 1, xtr, x, y, val);
        }
        updateY(xv, xtl, xtr, 1, 0, m - 1, x, y, val);
    }
    T query(int x1, int y1, int x2, int y2){
        return queryX(1, 0, n - 1, x1, y1, x2, y2);
    }
    T queryY(int xv, int yv, int ytl, int ytr, int y1, int y2){
        if(y1 > y2) return 0;
        else if(ytl == y1 && ytr == y2) return arr[xv][yv];
        else{
            int mid = ytl + (ytr - ytl) / 2;
            T q1 = queryY(xv, yv * 2, ytl, mid, y1, min(mid, y2));
            T q2 = queryY(xv, yv * 2 + 1, mid + 1, ytr, max(mid + 1, y1), y2);
            return q1 + q2;
        }
    }
    T queryX(int xv, int xtl, int xtr, int x1, int y1, int x2, int y2){
        if(x1 > x2) return 0;
        else if(xtl == x1 && xtr == x2) return queryY(xv, 1, 0, m - 1, y1, y2);
        else{
            int mid = xtl + (xtr - xtl) / 2;
            T q1 = queryX(xv * 2, xtl, mid, x1, y1, min(x2, mid), y2);
            T q2 = queryX(xv * 2 + 1, mid + 1, xtr, max(mid + 1, x1), y1, x2, y2);
            return q1 + q2;
        }
    }
};