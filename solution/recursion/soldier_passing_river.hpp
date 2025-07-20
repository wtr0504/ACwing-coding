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
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <utility>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>


vector<pair<int,int>> block = {{1,2},{2,1},{-1,-2},{-2,-1},{-1,2},{2,-1},{-2,1},{1,-2}};


void soldier_passing_river(){
    int m,n;
    int x,y;
    cin>>m>>n>>x>>y;
    vector<vector<long long>> dp(m + 1,vector<long long>(n + 1,0));
    dp[x][y] = -1;
    for(int i = 0;i < block.size();i++){
        int n_x = x + block[i].first;
        int n_y = y + block[i].second;
        if(n_x >= 0 && n_x <= m && n_y >= 0 && n_y <= n){
            dp[n_x][n_y] = -1;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= m;i++){
        if(dp[i][0] != -1 && dp[i - 1][0] != 0 && dp[i - 1][0] != -1)
            dp[i][0] = 1;
    }
    for(int i = 1;i <= n;i++){
        if(dp[0][i] != -1 && dp[0][i - 1] != 0 && dp[0][i - 1] != -1){
            dp[0][i] = 1;
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(dp[i][j] == -1) continue;
            dp[i][j] = (dp[i - 1][j] != -1 ? dp[i - 1][j] : 0) + (dp[i][j-1] != -1 ? dp[i][j-1] : 0);
        }
    }
    dp[m][n] = (dp[m - 1][n] != -1 ? dp[m - 1][n] : 0) + (dp[m][n-1] != -1 ? dp[m][n-1] : 0);
    cout<<dp[m][n]<<endl;
}

void solution(){
    soldier_passing_river();
}

int main(){
    solution();
    return 0;
}