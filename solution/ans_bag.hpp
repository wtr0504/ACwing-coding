using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <utility>
#include <vector>
#include <iomanip>
#include <tuple>
#include <map>

const int MOD = 1e9 + 7;

void ans_num_bag(){
    int n,v;
    while(cin>>n>>v){
        int m = 0;
        vector<int> weight(n);
        vector<int> value(n);
        for(int i = 0;i < n;i++){
            cin>>weight[i]>>value[i];
        }
        vector<int> dp(v + 1,0);
        vector<vector<int>> path(v + 1);
        for(int i = 0;i < n;i++){
            for(int j = v;j >= weight[i];j--){
                int new_val = dp[j - weight[i]] + value[i];
                if(new_val > dp[j]){
                    dp[j] = new_val;
                    path[j] = path[j - weight[i]];
                    path[j].push_back(i);
                } else if(new_val == dp[j]){
                    vector<int> new_path = path[j - weight[i]];
                    new_path.push_back(i);
                    if(path[j].empty() || path[j] > new_path){
                        path[j] = new_path;
                    }
                }
            }
        }
        int maxVal = 0;
        vector<int> res;
        for(int i = 0;i <=v;i++){
            if(maxVal < dp[i]){
                maxVal = dp[i];
                res = path[i];
            }else if(maxVal == dp[i]){
                if(path[i] < res){
                    res = path[i];
                }
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] + 1;
            if (i + 1 < res.size()) cout << " ";
        }
        cout << endl;
    }
}

void solution(){
    ans_num_bag();
}