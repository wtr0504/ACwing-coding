#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(100005);
bool visited_dfs[100005], visited_bfs[100005];

void dfs(int u) {
    if (visited_dfs[u]) return;
    visited_dfs[u] = true;
    cout << u << " ";
    for (int v : g[u]) {
        dfs(v);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited_bfs[u] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int v : g[x]) {
            if (!visited_bfs[v]) {
                visited_bfs[v] = true;
                q.push(v);
            }
        }
    }
}

void solution(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << endl;
    bfs(1);
    cout << endl;
}