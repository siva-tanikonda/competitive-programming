/*
KNUTH-MORRIS-PRATT (KMP)
Purpose: Finds all occurrences of a length-m string t in a length-n string s
Time Complexity: O(n)
Space Complexity: O(n)
*/

vector<bool> kmp(string s, string t) {
    int n = s.length();
    int m = t.length();
    if (!n || !m || m > n) return vector(n);
    vector<int> pat(m);
    int i = 1, j = 0;
    while (i < m) {
        if (t[i] == t[j]) pat[i++] = ++j;
        else if (j > 0) j = pat[j - 1];
        else i++;
    }
    vector<bool> ex(n);
    i = j = 0;
    while (i < n) {
        if (s[i] == t[j]) {
            j++;
            if (j == m) ex[i - m + 1] = true, j = pat[j - 1];
            i++;
        } else if (j > 0) j = pat[j - 1];
        else i++;
    }
    return ex;
}