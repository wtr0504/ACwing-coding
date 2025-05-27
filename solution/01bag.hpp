
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


void bag_01(){
    int n,v;
    while(cin>>n>>v){
        vector<int> value;
        vector<int> weight;
        for(int i = 0;i < n;i++){
            int val,w;
            cin>>w>>val;
            value.push_back(val);
            weight.push_back(w);
        }
        vector<vector<int>> dp(n,vector<int>(v + 1,0));
        for(int i = weight[0];i <= v;i++){
            dp[0][i] = value[0];
        }

        for(int i = 1;i < n;i++){
            for(int j = 0;j <= v;j++){
                if(j < weight[i]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j - weight[i]] + value[i]);
                }
            }
        }
        cout<<dp[n-1][v]<<endl;
    }
}

void solution(){
    bag_01();
}