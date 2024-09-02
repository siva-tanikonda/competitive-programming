/*
LINE CLASS
Purpose: This is just a class with basic geometric line functions
*/

template<class T> struct line{
    T m, b;
    bool v;
    line() : m(0), b(0), v(false) {}
    line(T x) : m(DBL_MAX), b(x), v(true) {}
    line(T _m, T _b) : m(_m), b(_b), v(false) {}
    line(T x1, T y1, T x2, T y2){
        if(x2 - x1 != 0){
            m = (y2 - y1) / (x2 - x1);
            b = y1 - m * x1, v = false;
        }else b = DBL_MAX, m = 0, v = true;
    }
    T evaluate(T x) const{ return m * x + b; }
    bool operator<(const line<T>& oth) const{
        if(m != oth.m) return m < oth.m;
        else return b < oth.b;
    }
    bool operator>(const line<T>& oth) const{
        if(m != oth.m) return m > oth.m;
        else return b > oth.b;
    }
    bool operator<=(const line<T>& oth) const{
        if(m != oth.m) return m <= oth.m;
        else return b <= oth.b;
    }
    bool operator>=(const line<T>& oth) const{
        if(m != oth.m) return m >= oth.m;
        else return b >= oth.b;
    }
    bool operator==(const line<T>& oth) const{
        return (m == oth.m && b == oth.b);
    }
};
pair<pair<T, T>, int> intersect(const line<T>& a, const line<T>& b){
    if(a.v && b.v){
        if(a.b == b.b) return make_pair(pair<T, T>(), 2);
        else return make_pair(pair<T, T>(), 0);
    }else if(a.v)
        return make_pair(make_pair(a.b, b.evaluate(a.b)), 1);
    else if(b.v)
        return make_pair(make_pair(b.b, a.evaluate(b.b)), 1);
    else{
        if(a.m == b.m){
            if(a.b == b.b) return make_pair(pair<T, T>(), 2);
            else return make_pair(pair<T, T>(), 0);
        }else{
            T x = (b.b - a.b) / (a.m - b.m);
            T y = a.evaluate(x);
            return make_pair(make_pair(x, y), 1);
        }
    }
}