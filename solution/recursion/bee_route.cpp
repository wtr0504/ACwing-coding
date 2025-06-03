#include "../common.hpp"


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
vector<vector<int>> dp(1005);


void bee_route(int n,int m) {
    if (m - n == 0) {
        cout << 0 << endl;
        return;
    }
    if (m - n == 1) {
        cout << 1 << endl;
        return;
    }

    dp[n] = {1};
    dp[n+1] = {1};
    for (int i = n + 2; i <= m; i++) {
        dp[i] = high_precision_add(dp[i - 1], dp[i - 2]);
    }

    for (int d : dp[m]) {
        cout << d;
    }
    cout << endl;
}

void solution(){
    int n,m;
    cin>>n>>m;
    bee_route(n, m);
}