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

void dim2_bag(){
    int n,v,m;
    while(cin>>n>>v>>m){
        vector<int> volume(n);
        vector<int> weight(n);
        vector<int> value(n);

        for(int i = 0;i < n;i++){
            cin>>volume[i]>>weight[i]>>value[i];
        }
        vector<vector<int>> dp(v + 1,vector<int>(m+1,0));

        for(int i = 0;i < n;i++){
            for(int j = v;j >= volume[i];j--){
                for(int k = m;k >= weight[i];k--){
                    dp[j][k] = max(dp[j][k],dp[j - volume[i]][k - weight[i]] + value[i]);
                }
            }
        }
        cout<<dp[v][m]<<endl;
    }
}

void solution(){
    dim2_bag();
}
