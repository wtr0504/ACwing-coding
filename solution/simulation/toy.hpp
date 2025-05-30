#include "../common.hpp"

void toy(){
    int n,m;
    while(cin>>n>>m){
        vector<pair<int,int>> dir(n);
        vector<string> jobs(n);
        for(int i = 0;i < n;i++){
            int a;
            cin>>a>>jobs[i];
            if(a == 0){
                dir[i] = {-1,1};
            }else{
                dir[i] = {1,-1};
            }
        }
        int cur = 0;
        for(int i = 0;i < m;i++){
            int a,s;
            cin>>a>>s;
            if(a == 0){
                cur += dir[cur].first * s;
            } else{
                cur += dir[cur].second * s;
            }
            if(cur < 0){
                cur =  n + cur;
            }
            cur %= n;
        }
        cout<<jobs[cur]<<endl;
    }
}

void solution(){
    toy();
}