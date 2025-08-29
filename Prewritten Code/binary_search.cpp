/*
BINARY SEARCH
Purpose: Finds the index of an element in a sorted list
Time Complexity: O(log(N))
Space Complexity: O(1)
*/

template<class T> T binary_search(vector<T> &arr, T val) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= val) r = mid;
        else l = mid + 1;
    }
    return (arr[l] == val) ? l : -1;
}
