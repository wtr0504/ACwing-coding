#include "../common.hpp"
#include <algorithm>
#include <climits>




void group(){
    int n;
    cin>>n;
    map<int,int> m;
    for(int i = 0;i < n;i++){
        int j;
        cin>>j;
        m[j]++;
    }
    int res = INT_MAX;
    while(!m.empty()){
        auto i = m.begin(),j = m.begin();
        j++;
        i->second--;
        int t = 1;
        for(;i->first == j->first - 1 && j->second > i->second;i++,j++){
            t++;
            j->second--;
        }
        res = min(res,t);
        i = m.begin();
        while(i != m.end() && i->second == 0){
            m.erase((i++)->first);
        }
    }
    cout<<res<<endl;
}

void solution(){
    group();
}