#include "../common.hpp"
#include <cstddef>
#include <iomanip>
#include <map>

void queue_water() {
    int n;
    cin >> n;
    vector<pair<int, int>> times(n);  

    for (int i = 0; i < n; ++i) {
        cin >> times[i].first;
        times[i].second = i + 1; 
    }

    sort(times.begin(), times.end());

    long long total_wait_time = 0;
    long long prefix = 0;

    for (int i = 0; i < n; ++i) {
        cout << times[i].second;
        if (i < n - 1) cout << " ";

        if (i != n - 1) {
            prefix += times[i].first;
            total_wait_time += prefix;
        }
    }
    cout << endl;

    cout << fixed << setprecision(2) << (double)total_wait_time / n << endl;
}


void solution(){
    queue_water();
}