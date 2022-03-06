#include <iostream>
#include <unordered_map>

using namespace std;

bool isSubstring(string s, string t) {
    int n1 = t.size();
    int n2 = s.size();
    if (n1 < n2)
        return false;
    if (n1 == n2) {
        for (int i = 0; i < n1; i++) {
            if (t[i] != s[i]) return false;
        }
        return true;
    }
    
    
    for (int offset = 0; offset < n1- n2; offset++) {
        int i = offset, j = i + n2 - 1;
        for (; i <= j; i++, j--) {
            if (t[i] != s[i-offset] || t[j] != s[j-offset])
                break;
        }
        if (i > j) 
            return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n;
        cin >> n;
        int cnt = 0;
        string num;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            if (isSubstring(num, to_string(i)))
                cnt++;
        }
        cout << cnt << endl;
    }
}