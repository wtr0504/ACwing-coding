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
        int w,val,c;
        vector<int> weight;
        vector<int> value;
        for(int i = 0;i < n;i++){
            cin>>w>>val>>c;
            int k = 1;
            while(k <= c){
                weight.push_back(k * w);
                value.push_back(k * val);
                c -= k;
                k *= 2;
            }
            if(c > 0){
                weight.push_back(c * w);
                value.push_back(c * val);
            }
        }
        vector<int> dp(v+1,0);

        for(int i = 0;i < weight.size();i++){
            for(int j = v;j >= weight[i];j--){
                dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
            }
        }
    
    cout<<dp[v]<<endl;

   }
}

void solution(){
    multi_bag();
}