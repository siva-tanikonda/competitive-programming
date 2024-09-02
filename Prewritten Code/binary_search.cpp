/*
BINARY SEARCH
Purpose: Finds the index of an element in a sorted list
Time Complexity: O(log(n))
Space Complexity: O(1)
*/

template<class T> T binary_search(vector<T> &a, T val) {
    int n = a.size();
    T l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (val <= a[mid]) r = mid;
        else l = mid + 1;
    }
    return (a[l] == val) ? l : -1;
}