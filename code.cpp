#include "solution/common.hpp"

// int main(){
//     solution();
// }

#include <iostream>
#include <vector>
using namespace std;

// 构建 next 数组（前缀函数）
vector<int> build_next(const string &pattern) {
    int m = pattern.size();
    vector<int> next(m, 0); // next[i] 表示 pattern[0...i] 的最长相等前后缀长度

    int j = 0;  // 当前前缀长度
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];  // 回退到前一个可能的前缀
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

// KMP 主过程
vector<int> kmp_search(const string &text, const string &pattern) {
    vector<int> next = build_next(pattern);
    vector<int> match_positions;

    int j = 0;
    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];  // 利用 next 数组回退
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == pattern.size()) {
            match_positions.push_back(i - j + 1); // 找到一次匹配
            j = next[j - 1]; // 继续找下一个匹配
        }
    }

    return match_positions;
}

int main() {
    string text = "ababcabcacbab";
    string pattern = "abcac";

    vector<int> result = kmp_search(text, pattern);
    for (int idx : result) {
        cout << "Match at index: " << idx << endl;
    }

    return 0;
}
