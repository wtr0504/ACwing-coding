#include "../common.hpp"



void roast_chicken(int n,int cur,int sum,vector<vector<int>>& res,vector<int> &path){
    if(sum > n || cur > 10)return;
    if(cur == 10){
        if(sum == n)
            res.push_back(path);
        return;
    }

    for(int j=1;j <= 3;j++){
            path[cur]=j;
            sum += j;
            roast_chicken(n,cur+1,sum,res,path);
            sum -= j;
    }
}


void solution(){
    int n;
    cin>>n;
    int sum =0;
    vector<int> path(10);
    vector<vector<int>> res;

    roast_chicken(n,0,sum,res,path);
    cout<<res.size()<<endl;
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < 10;j++){
            cout<<res[i][j]<<" ";
        }
    }
}