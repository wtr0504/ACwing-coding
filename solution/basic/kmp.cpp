#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int nxt[1000005];

void build_next() {
    int m = s2.size();
    int j = 0;
    nxt[0] = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && s2[i] != s2[j]) {
            j = nxt[j - 1];
        }
        if (s2[i] == s2[j]) {
            j++;
        }
        nxt[i] = j;
    }
}

void kmp() {
    int n = s1.size(), m = s2.size();
    int j = 0;
    for (int i = 0; i < n; i++) { // 从 i = 0 开始！
        while (j > 0 && s1[i] != s2[j]) {
            j = nxt[j - 1];
        }
        if (s1[i] == s2[j]) {
            j++;
        }
        if (j == m) {
            cout << (i - m + 2) << endl; // 匹配成功，输出起始下标
            j = nxt[j - 1]; // 继续匹配下一个
        }
    }
}

void solution() {
    cin >> s1 >> s2;
    build_next();
    kmp();
    for (int i = 0; i < s2.size(); i++) {
        cout << nxt[i] << " ";
    }
}


