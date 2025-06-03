#include "../common.hpp"

#define ll long long

vector<int> high_precision_add(const vector<int> &a, const vector<int> &b) {
    vector<int> res;
    int c = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || c) {
        int x = i >= 0 ? a[i] : 0;
        int y = j >= 0 ? b[j] : 0;
        int sum = x + y + c;
        res.push_back(sum % 10);
        c = sum / 10;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    return res;
}


void counting_stairs() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<vector<int>> dp(n + 1);
    dp[1] = {1};
    dp[2] = {2};
    for (int i = 3; i <= n; i++) {
        dp[i] = high_precision_add(dp[i - 1], dp[i - 2]);
    }

    for (int d : dp[n]) {
        cout << d;
    }
    cout << endl;
}

void solution(){
    counting_stairs();
}