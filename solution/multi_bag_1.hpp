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

void multi_bag(){
    int n,v;
    while(cin>>n>>v){
        vector<int> weight;
        vector<int> value;
        vector<int> count;
        for(int i = 0;i < n;i++){
            int w,val,c;
            cin>>w>>val>>c;
            weight.push_back(w);
            value.push_back(val);
            count.push_back(c);
        }
        vector<int> dp(v+1,0);
        for(int i = 0;i < n;i++){
            for(int j = v;j >= weight[i];j--){
                for(int k = 1;k <= count[i] && j >= k * weight[i];k++){
                    dp[j] = max(dp[j],dp[j - k * weight[i]] + k * value[i]);
                }
            }
        }
        cout<<dp[v]<<endl;
    }
}

void solution(){
    multi_bag();
}
