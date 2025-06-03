#include "../common.hpp"






void trible_kill() {
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    bool has_ans = false;
    vector<int> visited(10, 0);

    for (int i = 1; i <= 999 / k3; i++) {
        int a = k1 * i;
        int b = k2 * i;
        int c = k3 * i;

        if (b > 999 || c > 999) break; // 修复：扩大上限，防止过早终止

        bool t = true;
        int x = a, y = b, z = c;

        for (int j = 1; j <= 3; j++) {
            visited[x % 10]++;
            x /= 10;
        }
        for (int j = 1; j <= 3; j++) {
            visited[y % 10]++;
            y /= 10;
        }
        for (int j = 1; j <= 3; j++) {
            visited[z % 10]++;
            z /= 10;
        }

        if (visited[0] != 0) t = false;

        for (int j = 1; j <= 9; j++) {
            if (visited[j] != 1) {
                t = false;
                break;
            }
        }

        fill(visited.begin(), visited.end(), 0);

        if (t) {
            cout << a << " " << b << " " << c << endl;
            has_ans = true;
        }
    }

    if (!has_ans) {
        cout << "No!!!" << endl;
    }
}

void solution() {
    trible_kill();
}