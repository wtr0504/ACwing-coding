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
/**
 * 将混合背包转换为多重背包问题
 * count = -1 -》 count = 1
 * count = 0 -》count = v/w
 */

void hybird_bag(){
    int n,v;
    while(cin>>n>>v){
        vector<int> weight;
        vector<int> value;
        for(int i = 0;i < n;i++){
            int k = 1;
            int w,val,c;
            cin>>w>>val>>c;
            if(c == -1) c = 1;
            else if(c == 0) c = v / w;
            while(k <= c){
                weight.push_back(k*w);
                value.push_back(k*val);
                c -= k;
                k *= 2;
            }
            if(c > 0){
                weight.push_back(c * w);
                value.push_back(c * val);
            }
        }
        vector<int> dp(v + 1,0);
        for(int i = 0;i < weight.size();i++){
            for(int j = v;j >= weight[i];j--){
                dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
            }
        }
        cout<<dp[v]<<endl;
    }
}

void solution(){
    hybird_bag();
}