// Problem link: https://lightoj.com/problem/substring-frequency
// Time: O(m + n) / per case
// Space: O(m) / per case

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

#ifdef LOCAL
    #include "debug.h"
#else
    #define out(...) 0
#endif

vector<int> createLSP(string pattern) {
    vector<int> lps(pattern.length());
    int index = 0;
    for(int i = 1; i < pattern.length(); ) {
        if(pattern[i] == pattern[index]) {
            lps[i] = index + 1;
            i++;
            index++;
        } else {
            if(index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = index;
                i++;
            }
        }
    }
    return lps;
}

void kmp(string text, string pattern) {
    vector<int> lps = createLSP(pattern);
    int i = 0, j = 0;
    int res = 0;
    while(i < text.length()) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if(j == pattern.length()) {
            res++;
            j = lps[j - 1];
        }
    }
    cout << res << "\n";
}

void solve() {
    string a, b;
    cin >> a >> b;
    kmp(a, b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    for(int cs = 1; cs <= T; cs++) {
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}