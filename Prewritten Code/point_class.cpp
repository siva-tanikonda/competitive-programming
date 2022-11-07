/*
POINT CLASS
Purpose: This is just a class with basic geometric point functions
*/

template<class T> struct point{
    T x, y;
    point(): x(0), y(0) {}
    point(T _x, T _y) : x(_x), y(_y) {}
    point<T>& operator+=(const point<T>& oth){
        x += oth.x, y += oth.y;
        return *this;
    }
    point<T>& operator-=(const point<T>& oth){
        x -= oth.x, y -= oth.y;
        return *this;
    }
    point<T>& operator*=(const T& oth){
        x *= oth, y *= oth;
        return *this;
    }
    point<T>& operator/=(const T& oth){
        x /= oth, y /= oth;
        return *this;
    }
    point<T> operator+(const point<T>& oth) const{
        return point<T>(*this) += oth;
    }
    point<T> operator-(const point<T>& oth) const{
        return point<T>(*this) -= oth;
    }
    point<T> operator*(const T& oth) const{
        return point<T>(*this) *= oth;
    }
    point<T> operator/(const T& oth) const{
        return point<T>(*this) /= oth;
    }
    bool operator<(const point<T>& oth) const{
        if(x != oth.x) return x < oth.x;
        else return y < oth.y;
    }
    bool operator>(const point<T>& oth) const{
        if(x != oth.x) return x > oth.x;
        else return y > oth.y;
    }
    bool operator<=(const point<T>& oth) const{
        if(x != oth.x) return x <= oth.x;
        else return y <= oth.y;
    }
    bool operator>=(const point<T>& oth) const{
        if(x != oth.x) return x >= oth.x;
        else return y >= oth.y;
    }
    bool operator==(const point<T>& oth) const{
        return (x == oth.x && y == oth.y);
    }
};
T cross(const point<T>& a, const point<T>& b){
    return a.x * b.y - a.y * b.x;
}
T dot(const point<T>& a, const point<T>& b){
    return a.x * b.x + a.y * b.y;
}